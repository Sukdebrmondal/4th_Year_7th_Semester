import ipaddress
import re
from urllib.parse import urlparse


HOSTNAME_PATTERN = re.compile(
    r"(?=.{1,253}\Z)"
    r"(?:[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?\.)*"
    r"[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?"
)


def normalize_url(url):
    """
    Remove unnecessary spaces at the beginning and end.
    Add https:// when no scheme is provided.
    """

    url = url.strip()

    if not url:
        return ""

    # Do not modify input containing whitespace.
    # Validation will reject it.
    if any(character.isspace() for character in url):
        return url

    if "://" not in url:
        url = "https://" + url

    return url


def validate_url(url):
    """
    Validate whether the input is a usable HTTP/HTTPS URL.
    """

    if not url:
        return False, "URL cannot be empty."

    # Reject whitespace
    if any(character.isspace() for character in url):
        return False, "URL cannot contain whitespace."

    try:
        parsed = urlparse(url)

    except ValueError:
        return False, "Invalid URL format."

    # Only HTTP and HTTPS are supported
    if parsed.scheme.lower() not in ("http", "https"):
        return False, "Only HTTP and HTTPS URLs are supported."

    # Hostname must exist
    if not parsed.hostname:
        return False, "URL does not contain a valid hostname."

    hostname = parsed.hostname

    # Check IP address
    try:
        ipaddress.ip_address(hostname)

    except ValueError:

        # If it is not an IP, validate hostname format
        if len(hostname) > 253:
            return False, "URL contains an invalid hostname."

        if not HOSTNAME_PATTERN.fullmatch(hostname):
            return False, "URL contains an invalid hostname."

    # Validate port
    try:
        parsed.port

    except ValueError:
        return False, "Invalid port number."

    return True, "Valid URL."
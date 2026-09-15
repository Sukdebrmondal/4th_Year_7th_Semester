from urllib.parse import urlparse


def normalize_url(url):
    """
    Remove unnecessary spaces and add https://
    when the user does not provide a scheme.
    """

    url = url.strip()

    if not url:
        return ""

    if not url.startswith(("http://", "https://")):
        url = "https://" + url

    return url


def validate_url(url):
    """
    Validate whether the input is a usable HTTP/HTTPS URL.
    """

    if not url:
        return False, "URL cannot be empty."

    try:
        parsed = urlparse(url)

    except ValueError:
        return False, "Invalid URL format."

    if parsed.scheme not in ("http", "https"):
        return False, "Only HTTP and HTTPS URLs are supported."

    if not parsed.hostname:
        return False, "URL does not contain a valid hostname."

    try:
        parsed.port
    except ValueError:
        return False, "Invalid port number."

    return True, "Valid URL."
# from urllib.parse import urlparse
# import ipaddress
# import re


# def normalize_url(url):
#     """Return a trimmed URL with HTTPS added when no scheme is provided."""
#     url = url.strip()

#     if url and "://" not in url:
#         url = "https://" + url

#     return url


# def validate_url(url):
#     """Validate that a value is a usable HTTP or HTTPS URL."""
#     if not url:
#         return False, "URL cannot be empty."

#     if any(character.isspace() for character in url):
#         return False, "URL cannot contain whitespace."

#     try:
#         parsed = urlparse(url)
#         hostname = parsed.hostname
#         parsed.port
#     except ValueError:
#         return False, "URL contains an invalid hostname or port."

#     if parsed.scheme.lower() not in {"http", "https"}:
#         return False, "URL must use HTTP or HTTPS."

#     if not hostname:
#         return False, "URL must include a hostname."

#     if is_ip_address(hostname):
#         return True, "Valid URL."

#     if len(hostname) > 253 or not re.fullmatch(
#         r"(?=.{1,253}\Z)(?:[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?\.)*"
#         r"[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?",
#         hostname,
#     ):
#         return False, "URL contains an invalid hostname."

#     return True, "Valid URL."


# def is_ip_address(hostname):
#     if not hostname:
#         return False

#     try:
#         ipaddress.ip_address(hostname)
#     except ValueError:
#         return False

#     return True


# def parse_url(url):
#     parsed = urlparse(url)

#     print("URL:", url)
#     print("Scheme:", parsed.scheme)
#     print("Hostname:", parsed.hostname)
#     print("Port:", parsed.port)
#     print("Path:", parsed.path)
#     print("Query:", parsed.query)




from urllib.parse import urlparse


def parse_url(url):
    """
    Parse a URL and display its basic components.
    """

    parsed = urlparse(url)

    print("URL:", url)
    print("Scheme:", parsed.scheme)
    print("Hostname:", parsed.hostname)
    print("Port:", parsed.port)
    print("Path:", parsed.path)
    print("Query:", parsed.query)
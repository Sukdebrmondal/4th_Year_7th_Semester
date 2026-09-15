from urllib.parse import urlparse
import re
import ipaddress


def extract_features(url):

    parsed = urlparse(url)

    features = {}

    # 1. URL Length
    features["url_length"] = len(url)

    # 2. HTTPS
    features["https"] = parsed.scheme.lower() == "https"

    # 3. IP Address
    features["is_ip"] = is_ip_address(parsed.hostname)

    # 4. Number of Dots
    features["dot_count"] = url.count(".")

    # 5. Number of Hyphens
    features["hyphen_count"] = url.count("-")

    # 6. @ Symbol
    features["has_at_symbol"] = "@" in url

    # 7. Number of Subdomains
    features["subdomain_count"] = count_subdomains(parsed.hostname)

    # 8. Suspicious Keywords
    features["suspicious_keywords"] = find_suspicious_keywords(url)

    # 9. URL Depth
    features["url_depth"] = count_url_depth(parsed.path)

    # 10. Special Characters
    features["special_char_count"] = count_special_characters(url)

    return features


def is_ip_address(hostname):

    if hostname is None:
        return False

    try:
        ipaddress.ip_address(hostname)
        return True

    except ValueError:
        return False


def count_subdomains(hostname):

    if hostname is None:
        return 0

    parts = hostname.split(".")

    if len(parts) <= 2:
        return 0

    return len(parts) - 2


def find_suspicious_keywords(url):

    keywords = [
        "login",
        "signin",
        "verify",
        "verification",
        "secure",
        "account",
        "update",
        "password",
        "bank",
        "confirm"
    ]

    url_lower = url.lower()

    found = []

    for keyword in keywords:

        if keyword in url_lower:
            found.append(keyword)

    return found


def count_url_depth(path):

    if not path or path == "/":
        return 0

    parts = path.strip("/").split("/")

    return len(parts)


def count_special_characters(url):

    special_characters = re.findall(
        r"[^a-zA-Z0-9]",
        url
    )

    return len(special_characters)
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
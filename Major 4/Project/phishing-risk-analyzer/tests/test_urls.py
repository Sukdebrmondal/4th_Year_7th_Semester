import sys

sys.path.append("src")

from validator import normalize_url, validate_url
from feature_extractor import extract_features
from risk_engine import calculate_risk


def test_normalize_url():

    result = normalize_url("example.com")

    assert result == "https://example.com"


def test_empty_url():

    valid, message = validate_url("")

    assert valid is False


def test_valid_url():

    valid, message = validate_url("https://example.com")

    assert valid is True


def test_ip_detection():

    features = extract_features(
        "http://192.168.1.10/login"
    )

    assert features["is_ip"] is True


def test_https_detection():

    features = extract_features(
        "https://example.com"
    )

    assert features["https"] is True


def test_suspicious_keyword():

    features = extract_features(
        "https://example.com/login/verify"
    )

    assert "login" in features["suspicious_keywords"]
    assert "verify" in features["suspicious_keywords"]


def test_risk_engine():

    features = extract_features(
        "http://192.168.1.10/login"
    )

    score, level, reasons = calculate_risk(features)

    assert score > 0
    assert level in ["LOW", "MEDIUM", "HIGH", "CRITICAL"]
    assert len(reasons) > 0
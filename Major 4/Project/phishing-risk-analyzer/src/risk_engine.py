def calculate_risk(features):

    score = 0
    rules = []

    # Rule 1: IP Address
    if features["is_ip"]:

        points = 20
        score += points

        rules.append({
            "name": "IP Address",
            "points": points,
            "triggered": True,
            "reason": "IP address is used instead of a domain name."
        })

    else:

        rules.append({
            "name": "IP Address",
            "points": 0,
            "triggered": False,
            "reason": "A domain name is used."
        })

    # Rule 2: HTTP instead of HTTPS
    if not features["https"]:

        points = 10
        score += points

        rules.append({
            "name": "HTTPS",
            "points": points,
            "triggered": True,
            "reason": "HTTPS is not being used."
        })

    else:

        rules.append({
            "name": "HTTPS",
            "points": 0,
            "triggered": False,
            "reason": "HTTPS is being used."
        })

    # Rule 3: Suspicious Keywords
    keywords = features["suspicious_keywords"]

    if len(keywords) > 0:

        points = min(len(keywords) * 5, 25)
        score += points

        rules.append({
            "name": "Suspicious Keywords",
            "points": points,
            "triggered": True,
            "reason": "Suspicious keywords detected: "
                      + ", ".join(keywords)
        })

    else:

        rules.append({
            "name": "Suspicious Keywords",
            "points": 0,
            "triggered": False,
            "reason": "No suspicious keywords detected."
        })

    # Rule 4: @ Symbol
    if features["has_at_symbol"]:

        points = 15
        score += points

        rules.append({
            "name": "@ Symbol",
            "points": points,
            "triggered": True,
            "reason": "@ symbol detected in the URL."
        })

    else:

        rules.append({
            "name": "@ Symbol",
            "points": 0,
            "triggered": False,
            "reason": "No @ symbol detected."
        })

    # Rule 5: Long URL
    if features["url_length"] > 75:

        points = 10
        score += points

        rules.append({
            "name": "Long URL",
            "points": points,
            "triggered": True,
            "reason": "URL is unusually long."
        })

    else:

        rules.append({
            "name": "Long URL",
            "points": 0,
            "triggered": False,
            "reason": "URL length is within the normal threshold."
        })

    # Rule 6: Multiple Subdomains
    if features["subdomain_count"] >= 3:

        points = 10
        score += points

        rules.append({
            "name": "Multiple Subdomains",
            "points": points,
            "triggered": True,
            "reason": "Multiple subdomains detected."
        })

    else:

        rules.append({
            "name": "Multiple Subdomains",
            "points": 0,
            "triggered": False,
            "reason": "No excessive number of subdomains detected."
        })

    # Rule 7: Multiple Hyphens
    if features["hyphen_count"] >= 3:

        points = 5
        score += points

        rules.append({
            "name": "Multiple Hyphens",
            "points": points,
            "triggered": True,
            "reason": "Multiple hyphens detected in the URL."
        })

    else:

        rules.append({
            "name": "Multiple Hyphens",
            "points": 0,
            "triggered": False,
            "reason": "No excessive number of hyphens detected."
        })

    # Rule 8: Deep URL Path
    if features["url_depth"] >= 4:

        points = 5
        score += points

        rules.append({
            "name": "Deep URL Path",
            "points": points,
            "triggered": True,
            "reason": "URL contains a deep path structure."
        })

    else:

        rules.append({
            "name": "Deep URL Path",
            "points": 0,
            "triggered": False,
            "reason": "URL path depth is within the threshold."
        })

    # Maximum score = 100
    score = min(score, 100)

    # Determine risk level
    if score <= 30:

        risk_level = "LOW"

    elif score <= 60:

        risk_level = "MEDIUM"

    elif score <= 80:

        risk_level = "HIGH"

    else:

        risk_level = "CRITICAL"

    return score, risk_level, rules
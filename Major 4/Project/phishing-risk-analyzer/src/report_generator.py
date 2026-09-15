def generate_report(url, features, score, risk_level, rules):

    print()
    print("==========================================")
    print("        PHISHING RISK ANALYSIS REPORT")
    print("==========================================")

    print()
    print("Analyzed URL:")
    print(url)

    print()
    print("========== URL FEATURES ==================")

    print("URL Length          :", features["url_length"])
    print("HTTPS               :", features["https"])
    print("IP Address          :", features["is_ip"])
    print("Number of Dots      :", features["dot_count"])
    print("Number of Hyphens   :", features["hyphen_count"])
    print("@ Symbol Present    :", features["has_at_symbol"])
    print("Subdomains          :", features["subdomain_count"])
    print("Suspicious Keywords :", features["suspicious_keywords"])
    print("URL Depth           :", features["url_depth"])
    print("Special Characters  :", features["special_char_count"])

    print()
    print("========== RISK ANALYSIS =================")

    print("Risk Score           :", score, "/ 100")
    print("Risk Level           :", risk_level)

    print()
    print("========== SCORE BREAKDOWN ===============")

    for rule in rules:

        print(
            "{:<24} +{}".format(
                rule["name"],
                rule["points"]
            )
        )

    print("------------------------------------------")
    print("Total Risk Score      :", score, "/ 100")

    print()
    print("========== SECURITY REASONS ==============")

    triggered_rules = []

    for rule in rules:

        if rule["triggered"]:
            triggered_rules.append(rule)

    if len(triggered_rules) == 0:

        print(
            "No major suspicious characteristics detected."
        )

    else:

        for rule in triggered_rules:

            print("[!] " + rule["reason"])

    print()
    print("========== RECOMMENDATION ================")

    if risk_level == "LOW":

        print(
            "The URL shows few suspicious characteristics."
        )

        print(
            "Still verify the website before entering "
            "sensitive information."
        )

    elif risk_level == "MEDIUM":

        print(
            "The URL contains some suspicious characteristics."
        )

        print(
            "Proceed with caution and verify the website "
            "independently."
        )

    elif risk_level == "HIGH":

        print(
            "The URL contains several suspicious characteristics."
        )

        print(
            "Avoid entering passwords or sensitive information."
        )

    else:

        print(
            "The URL contains many suspicious characteristics."
        )

        print(
            "Avoid visiting the website and do not enter "
            "sensitive information."
        )

    print()
    print("==========================================")
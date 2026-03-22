# 🔐 Secure Multi-Hop Localization Protocol

> Sécurisation du protocole de localisation multi-sauts en utilisant OpenSSL — RSA Encryption & RSA Signature (SHA-256)

---

## 📖 Overview

This project implements a **secure multi-hop localization protocol** for wireless networks. In multi-hop localization, a node estimates its physical position by communicating with a series of intermediate nodes (hops) that relay location-relevant messages. Without security, these messages are vulnerable to relay attacks, spoofing, and man-in-the-middle interception.

This implementation hardens the protocol using **OpenSSL**, applying:

- **RSA Encryption** — to ensure message confidentiality across each hop
- **RSA Digital Signatures with SHA-256** — to guarantee message authenticity and integrity at every relay point

---

## 🎯 Objectives

- Protect localization messages from eavesdropping and tampering
- Authenticate the identity of each node participating in the multi-hop chain
- Ensure non-repudiation of transmitted localization data
- Demonstrate a practical application of asymmetric cryptography in network-layer security

---

## 🏗️ Architecture

```
[Node A] ──encrypt+sign──► [Relay 1] ──verify+re-sign──► [Relay 2] ──► ... ──► [Anchor/Server]
            RSA pub(R1)                  RSA pub(R2)
```

Each node in the chain:
1. **Verifies** the incoming message's signature using the sender's public key
2. **Decrypts** the message payload with its own private key
3. **Re-signs** and **re-encrypts** the forwarded message for the next hop

---

## 🔧 Technologies

| Component | Details |
|-----------|---------|
| Language | C |
| Cryptography Library | OpenSSL |
| Encryption | RSA (asymmetric) |
| Hashing / Signing | SHA-256 + RSA signature |
| Protocol Layer | Custom multi-hop localization |

---

## 📋 Prerequisites

Make sure the following are installed on your system:

```bash
# Debian/Ubuntu
sudo apt-get update
sudo apt-get install libssl-dev openssl build-essential

# Fedora/RHEL
sudo dnf install openssl-devel openssl gcc make
```

Verify your OpenSSL installation:

```bash
openssl version
```

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/ihebxsl/Localisation.git
cd Localisation
```

### 2. Generate RSA Key Pairs

Each node (sender, relays, anchor) requires its own RSA key pair. Generate them with:

```bash
# Generate a 2048-bit private key
openssl genrsa -out private_key.pem 2048

# Extract the corresponding public key
openssl rsa -in private_key.pem -pubout -out public_key.pem
```

Repeat for each node in your topology.

### 3. Build the Project

```bash
make
```

Or compile manually:

```bash
gcc -o localisation main.c crypto_utils.c -lssl -lcrypto
```

### 4. Run the Protocol

```bash
./localisation
```

---

## 🔑 Cryptographic Details

### RSA Encryption

Messages are encrypted using the **recipient's public key**, ensuring only the holder of the corresponding private key can decrypt them.

```c
RSA_public_encrypt(msg_len, message, encrypted, rsa_pub, RSA_PKCS1_OAEP_PADDING);
```

### RSA Signature with SHA-256

Messages are signed using the **sender's private key**. Any node can verify authenticity using the sender's public key.

```c
// Sign
EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, pkey);
EVP_DigestSignUpdate(ctx, message, msg_len);
EVP_DigestSignFinal(ctx, signature, &sig_len);

// Verify
EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, pkey);
EVP_DigestVerifyUpdate(ctx, message, msg_len);
EVP_DigestVerifyFinal(ctx, signature, sig_len);
```

### Security Properties Achieved

| Property | Mechanism |
|----------|-----------|
| Confidentiality | RSA Encryption (OAEP padding) |
| Integrity | SHA-256 hash |
| Authenticity | RSA Digital Signature |
| Non-repudiation | Private-key-bound signature |

---

## 📁 Project Structure

```
Localisation/
├── src/
│   ├── main.c              # Entry point and protocol orchestration
│   ├── crypto_utils.c      # RSA encryption/decryption & signing functions
│   └── localization.c      # Multi-hop localization logic
├── include/
│   ├── crypto_utils.h
│   └── localization.h
├── keys/                   # Directory for PEM key files (not committed)
├── Makefile
└── README.md
```

> ⚠️ **Note:** Never commit private keys (`private_key.pem`) to version control. Add `keys/` to your `.gitignore`.

---

## 🧪 Testing

Run the test suite to verify the cryptographic operations:

```bash
make test
./tests/run_tests
```

Tests cover:
- Key generation and loading
- Encrypt → Decrypt round-trip
- Sign → Verify round-trip
- Tampered message detection (signature rejection)
- Full multi-hop message relay simulation

---

## ⚠️ Security Considerations

- Keys should be **at least 2048 bits** (4096-bit recommended for production)
- Use **OAEP padding** for RSA encryption (never raw/PKCS1 v1.5 in new code)
- Rotate key pairs periodically in a real deployment
- This project is intended for **educational and research purposes**; additional hardening is needed for production use

---

## 📚 References

- [OpenSSL Documentation](https://docs.openssl.org/)
- [RFC 8017 — PKCS #1: RSA Cryptography Specifications](https://datatracker.ietf.org/doc/html/rfc8017)
- Capkun, S., Hamdi, M., & Hubaux, J.P. — *GPS-free positioning in mobile ad-hoc networks*
- Lazos, L., & Poovendran, R. — *SeRLoc: Secure Range-Independent Localization for Wireless Sensor Networks*

---

## 👤 Author

**Iheb** — [@ihebxsl](https://github.com/ihebxsl)

---

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

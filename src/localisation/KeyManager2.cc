#include "KeyManager2.h"
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <iostream>
#include "KeyManager2.h"
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <iomanip>
#include <sstream>

// Initialize static variables
EVP_PKEY* KeyManager2::privateKey2 = nullptr;
EVP_PKEY* KeyManager2::publicKey2 = nullptr;
bool KeyManager2::keysGenerated2 = false;

// Generate RSA keys
void KeyManager2::generateRSAKeys2() {
    if (!keysGenerated2) {
        RSA* rsa = RSA_new();


        BIGNUM* exponent = BN_new();
        BN_set_word(exponent, RSA_F4);
        int smaller_key_size = 512;
        RSA_generate_key_ex(rsa, smaller_key_size, exponent, nullptr);



        privateKey2 = EVP_PKEY_new();
        publicKey2 = EVP_PKEY_new();


        EVP_PKEY_assign_RSA(privateKey2, rsa);
        EVP_PKEY_assign_RSA(publicKey2, rsa);

        // Create memory BIOs to hold the PEM formatted keys
        BIO* privateKeyBio = BIO_new(BIO_s_mem());
        BIO* publicKeyBio = BIO_new(BIO_s_mem());


        PEM_write_bio_PrivateKey(privateKeyBio, privateKey2, nullptr, nullptr, 0, nullptr, nullptr);


        PEM_write_bio_PUBKEY(publicKeyBio, publicKey2);


        int privateKeyLength = BIO_pending(privateKeyBio);
        int publicKeyLength = BIO_pending(publicKeyBio);


        char* privateKeyBuffer = new char[privateKeyLength + 1];
        char* publicKeyBuffer = new char[publicKeyLength + 1];


        BIO_read(privateKeyBio, privateKeyBuffer, privateKeyLength);
        BIO_read(publicKeyBio, publicKeyBuffer, publicKeyLength);


        privateKeyBuffer[privateKeyLength] = '\0';
        publicKeyBuffer[publicKeyLength] = '\0';


        std::cout << "Private Key:" << std::endl << privateKeyBuffer << std::endl;
        std::cout << "Public Key:" << std::endl << publicKeyBuffer << std::endl;

        // Clean up
        delete[] privateKeyBuffer;
        delete[] publicKeyBuffer;
        BIO_free(privateKeyBio);
        BIO_free(publicKeyBio);

        // Set flag to indicate keys have been generated
        keysGenerated2 = true;
    }
}
// Signer les données avec la clé privée RSA
bool KeyManager2::signData(const unsigned char* data, size_t data_len, unsigned char* signature, unsigned int* signature_len) {
    if (!privateKey2) {
        std::cerr << "Clé privée non initialisée." << std::endl;
        return false;
    }

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) {
        std::cerr << "Erreur lors de la création du contexte de hachage." << std::endl;
        return false;
    }

    if (EVP_SignInit_ex(ctx, EVP_sha256(), nullptr) != 1) {
        std::cerr << "Erreur lors de l'initialisation du hachage." << std::endl;
        EVP_MD_CTX_free(ctx);
        return false;
    }

    if (EVP_SignUpdate(ctx, data, data_len) != 1) {
        std::cerr << "Erreur lors de la mise à jour du hachage." << std::endl;
        EVP_MD_CTX_free(ctx);
        return false;
    }

    if (EVP_SignFinal(ctx, signature, signature_len, privateKey2) != 1) {
        std::cerr << "Erreur lors de la signature des données." << std::endl;
        EVP_MD_CTX_free(ctx);
        return false;
    }

    EVP_MD_CTX_free(ctx);
    return true;
}


// Convertir une signature en une chaîne hexadécimale
std::string KeyManager2::signatureToHexString(const unsigned char* signature, unsigned int signature_len) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (unsigned int i = 0; i < signature_len; ++i) {
        ss << std::setw(2) << static_cast<unsigned>(signature[i]);
    }
    return ss.str();
}

// Vérifier une signature avec une clé publique
bool KeyManager2::verifySignature(const unsigned char* data, size_t data_len, const unsigned char* signature, size_t signature_len, EVP_PKEY* publicKey) {
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) {
        std::cerr << "Erreur lors de la création du contexte de hachage." << std::endl;
        return false;
    }

    if (EVP_VerifyInit_ex(ctx, EVP_sha256(), nullptr) != 1) {
        std::cerr << "Erreur lors de l'initialisation de la vérification de signature." << std::endl;
        EVP_MD_CTX_free(ctx);
        return false;
    }

    if (EVP_VerifyUpdate(ctx, data, data_len) != 1) {
        std::cerr << "Erreur lors de la mise à jour de la vérification de signature." << std::endl;
        EVP_MD_CTX_free(ctx);
        return false;
    }

    int verifyResult = EVP_VerifyFinal(ctx, signature, signature_len, publicKey);
    EVP_MD_CTX_free(ctx);

    if (verifyResult != 1) {
        //std::cerr << "La vérification de signature a échoué." << std::endl;
        return false;
    }

    return true;
}
EVP_PKEY* KeyManager2::getPrivateKey2() {
    return privateKey2;
}


EVP_PKEY* KeyManager2::getPublicKey2() {
    return publicKey2;
}

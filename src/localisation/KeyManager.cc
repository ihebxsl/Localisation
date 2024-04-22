#include "KeyManager.h"
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <iostream>

// Initialize static variables
EVP_PKEY* KeyManager::privateKey = nullptr;
EVP_PKEY* KeyManager::publicKey = nullptr;
bool KeyManager::keysGenerated = false;

// Generate RSA keys
void KeyManager::generateRSAKeys() {
    if (!keysGenerated) {
        RSA* rsa = RSA_new();


        BIGNUM* exponent = BN_new();
        BN_set_word(exponent, RSA_F4);
        int smaller_key_size = 512;
        RSA_generate_key_ex(rsa, smaller_key_size, exponent, nullptr);



        privateKey = EVP_PKEY_new();
        publicKey = EVP_PKEY_new();


        EVP_PKEY_assign_RSA(privateKey, rsa);
        EVP_PKEY_assign_RSA(publicKey, rsa);

        // Create memory BIOs to hold the PEM formatted keys
        BIO* privateKeyBio = BIO_new(BIO_s_mem());
        BIO* publicKeyBio = BIO_new(BIO_s_mem());


        PEM_write_bio_PrivateKey(privateKeyBio, privateKey, nullptr, nullptr, 0, nullptr, nullptr);


        PEM_write_bio_PUBKEY(publicKeyBio, publicKey);


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
        keysGenerated = true;
    }
}


EVP_PKEY* KeyManager::getPrivateKey() {
    return privateKey;
}


EVP_PKEY* KeyManager::getPublicKey() {
    return publicKey;
}

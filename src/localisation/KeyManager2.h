// KeyManager2.h

#ifndef KEYMANAGER2_H
#define KEYMANAGER2_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

class KeyManager2 {
private:
    static EVP_PKEY* privateKey2;
    static EVP_PKEY* publicKey2;
    static bool keysGenerated2;

public:
    static void generateRSAKeys2();
    static bool signData(const unsigned char* data, size_t data_len, unsigned char* signature, unsigned int* signature_len);
    static bool verifySignature(const unsigned char* data, size_t data_len, const unsigned char* signature, size_t signature_len, EVP_PKEY* publicKey);
    static std::string signatureToHexString(const unsigned char* signature, unsigned int signature_len);
    static EVP_PKEY* getPrivateKey2();
    static EVP_PKEY* getPublicKey2();
};

#endif // KEYMANAGER2_H

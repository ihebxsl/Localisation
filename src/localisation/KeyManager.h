// KeyManager.h

#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

class KeyManager {
private:
    static EVP_PKEY* privateKey;
    static EVP_PKEY* publicKey;
    static bool keysGenerated;

public:
    static void generateRSAKeys();
    static EVP_PKEY* getPrivateKey();
    static EVP_PKEY* getPublicKey();
};

#endif // KEYMANAGER_H

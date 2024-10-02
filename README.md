<h1 align="center">ChaCha20 Implementation</h1>
This repository contains a C implementation of the stream cipher algorithm ChaCha. Find below some useful links that were used throughout the development of this project:

- [Paper](https://cr.yp.to/chacha/chacha-20080120.pdf)

- [RFC](https://datatracker.ietf.org/doc/html/draft-agl-tls-chacha20poly1305-04#section-7)

- [Algorithm Explanation](https://musigma.blog/2021/02/06/chacha.html)
  
- [Algorithm Design](https://loup-vaillant.fr/tutorials/chacha20-design)

---

<h3>Introductory Questions:</h3>

- ***What is a stream cipher? What makes a stream cipher different from a block cipher?***
  
A stream cipher is a type of encryption algorithm that encrypts byte by byte (or bit by bit) continuously. 
Block ciphers, instead, break the plaintext into sections (blocks of 64 or 128 bits) and operate on those blocks to encrypt the plaintext.


- ***What is an AEAD?***

"Authenticated Encryption with Associated Data": Encryption that confirms whether the message has been modified or not.
"Associated Data" speaks for the additional data included that must be authenticated yet not encrypted (Example: A packet header that should be readable but not altered).


- ***What is Poly1305?***

Message authentication code (MAC) algorithm that verifies the integrity and authenticity of data.
Typically used in ChaCha20 for the authentication part of the process.

- ***What are test vectors?***

Pre-defined plaintexts and expected ciphertext used to test cryptographic algorithms.

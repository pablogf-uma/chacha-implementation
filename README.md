<h1 align="center">ChaCha20 Implementation</h1>


This repository contains a C implementation of the stream cipher algorithm ChaCha20.


<h2>Contents:</h2>

- Source code of the algorithm.
- Test vectors (3 from RFC 8439 and a total of 5) that confirm the correct functioning algorithm.
- A python script that generates custom test vectors.

<h2>Performance:</h2>

- Throughput: 135.5 MB/second with an i7-13620H Intel processor.

- Performs 2.5 million encryptions for different 512-bit plaintexts in 1 second.

<h2>Resources:</h2>

These resources were used throughout the development of the project outlined above.

- [Paper](https://cr.yp.to/chacha/chacha-20080120.pdf)

- [RFC 8439](https://www.rfc-editor.org/rfc/rfc8439#section-2.1.1)

- [Algorithm Explanation](https://musigma.blog/2021/02/06/chacha.html)
  
- [Algorithm Design](https://loup-vaillant.fr/tutorials/chacha20-design)

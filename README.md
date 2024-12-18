<h1 align="center">ChaCha20 Implementation</h1>

This repository contains a **C implementation** of the stream cipher algorithm **ChaCha20**.

---

## Contents

- Source code of the algorithm.
- Test vectors (3 from [RFC 8439](https://www.rfc-editor.org/rfc/rfc8439) and a total of 5) to confirm the correct functioning of the algorithm.
- A Python script that generates custom test vectors.

---

## Resources

The following resources were used throughout the development of this project:

- [Paper](https://cr.yp.to/chacha/chacha-20080120.pdf)  
  Original research paper on ChaCha20 by Daniel J. Bernstein.

- [RFC 8439](https://www.rfc-editor.org/rfc/rfc8439#section-2.1.1)  
  Standardized specification of ChaCha20 and its use in internet protocols.

- [Algorithm Explanation](https://musigma.blog/2021/02/06/chacha.html)  
  A detailed explanation of how the ChaCha20 algorithm works.

- [Algorithm Design](https://loup-vaillant.fr/tutorials/chacha20-design)  
  A guide to understanding the design principles of ChaCha20.

---

## Files

The project consists of several source files, each handling a specific aspect of the ChaCha20 algorithm:

- **Makefile**  
  Contains build instructions for the project.

- **chacha20.c**  
  Main implementation of the ChaCha20 algorithm.

- **quarter_round.c**  
  Implementation of the quarter round function used in the algorithm.

- **state_init.c**  
  Functions for initializing the state.

- **permute_state.c**  
  Functions for permuting the state.

- **encrypt.c**  
  Functions for encryption.

- **run_encrypt_test.c**  
  A test for encryption functionality.

- **calculate_throughput.c**  
  Functions for calculating throughput.

- **decrypt.c**  
  Functions for decryption.

- **run_decrypt_test.c**  
  A test for decryption functionality.

- **encrypt_custom_input.c**  
  Functions for encrypting custom inputs.

- **decrypt_custom_input.c**  
  Functions for decrypting custom inputs.

---

## Tests

The compiled executable, `chacha20`, supports the following options for testing and usage:

- Run all available tests: Tests vectors (decryption and encryption), and clock cycle tests
```c
./chacha20 --all-tests
````
- Encrypt test vector N (where N is an from 1 to 5 for each test vector within the [RFC 8439](https://www.rfc-editor.org/rfc/rfc8439#section-2.1.1)).
```c
./chacha20 --enc-tv N
```
- Decrypt test vector N (where N is an from 1 to 5).
```c
./chacha20 --dec-tv N
```
- Clock cycles tests N (where N is from 1 to 5 for each plaintext length per [ECRYPT](https://bench.cr.yp.to/results-stream/amd64-panther.html)).
```c
./chacha20 --clock-ct N
```
Encrypt a custom input provided by the user.
```c
./chacha20 --enc-ci
```
- Decrypt a custom input provided by the user.
```c
./chacha20 --dec-ci
```

---

## Performance

This implementation of ChaCha20 has been optimized for performance and includes benchmarking scripts to measure its efficiency. The results are comparable to established benchmarks, such as those available at [ECRYPT](https://bench.cr.yp.to/results-stream/amd64-panther.html).
To measure the **cycles per byte**, use the provided automation scripts:

#### Windows
Run the `clock_cycles_tests.bat` script:
```bash
clock_cycles_tests.bat
```

### Linux
Run the `clock_cycles_tests.sh` script:
```bash
clock_cycles_tests.sh
```
These scripts perform automated benchmarking of the ChaCha20 implementation, similar to how benchmarks are conducted for cryptographic algorithms at [ECRYPT](https://bench.cr.yp.to/results-stream/amd64-panther.html). The average and median results in cycles per byte are as follows:

| Plaintext Length | Average | Median |
|------------------|---------|--------|
| 8-bytes         | 168.82  | 155.38 |
| 64-bytes        | 21.27   | 20.99  |
| 576-bytes       | 11.30   | 11.34  |
| 1536-bytes      | 10.12   | 9.04   |
| 4096-bytes      | 12.02   | 10.19  |

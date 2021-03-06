#include <cstdio>
#include <cstdint>
#include <cstring>

const int N=10001;

const uint8_t s[16] =
  {6,8,2,3, 9,10,5,12,
   1,14,4,7, 11,13,0,15};

void sbox(int n, uint8_t *a) {
  for (int i=0; i<n; i++) {
    a[i] = (s[a[i]>>4]<<4) | s[a[i] & 0x0f];
  }
}

uint8_t dec(char c) {
  if ('0' <= c && c <= '9') return c-'0';
  if ('a' <= c && c <= 'f') return c-'a'+10;
  // error!
  return 0;
}

void hex_to_bin(char* s, uint8_t* b) {
  int n = strlen(s);
  for (int i=0, j=0; i<n; i+=2, j++) {
    // b[j] = dec(s[i]*16) + dec(s[i+1]);
    b[j] = (dec(s[i]) << 4) | dec(s[i+1]);
  }
}

char hex(uint8_t x) {
  if (x < 10)
    return x+'0';
  else
    return x-10+'a';
  // x >= 16 - error!
}

void bin_to_hex(int n, uint8_t* b, char* s) {
  for (int i=0, j=0; i<n; i++, j+=2) {
    // s[j]  = hex(b[i]/16);
    s[j] = hex(b[i] >> 4);
    // s[j+1]= hex(b[i]%16);
    s[j+1] = hex(b[i] & 0x0f);
  }
  s[2*n+1]= '\0';
}

int main() {
  char* s = new char[N];
  scanf("%s",s);

  int n = strlen(s);
  int m = n/2;
  uint8_t* b = new uint8_t[m];

  hex_to_bin(s,b);

  sbox(m,b);

  char* t = new char[2*m+1];
  bin_to_hex(m,b,t);

  printf("%s\n",t);

  return 0;
}

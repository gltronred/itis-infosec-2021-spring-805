#include <cstdio>
#include <cstdint>
#include <cstring>

int N=10001;

uint8_t dec(char c) {
  if ('0' <= c && c <= '9') return c-'0';
  if ('a' <= c && c <= 'f') return c-'a'+10;
  return 0;
}

void hex_to_bin(char* s, uint8_t* b) {
  int n = strlen(s);
  for (int i=0, j=0; i<n; i+=2, j++) {
    // b[j] = dec(s[i]) * 16 + dec(s[i+1]);
    b[j] = (dec(s[i]) << 4) | dec(s[i+1]);
  }
}

char hex(uint8_t x) {
  if (x < 10)
    return x+'0';
  else
    return x+'a'-10;
}

void bin_to_hex(int n, uint8_t* b, char* s) {
  for (int i=0, j=0; i<n; i++, j+=2) {
    // s[j] = hex(b[i]/16);
    s[j] = hex(b[i] >> 4);
    // s[j+1]=hex(b[i]%16);
    s[j+1] = hex(b[i] & 0x0f);
  }
  s[2*n+1] = '\0';
}

void swap_halves(int n, uint8_t* a, uint8_t* b) {
  for (int i=0; i<n; i++)
    b[i] = (a[i] >> 4) | (a[i] << 4);
}

// 0x1234567890abcdef -> 0x2143658709badcfe
int64_t swap2(int64_t a) {
  return ((a & 0xf0f0f0f0f0f0f0f0) >> 4) |
         ((a & 0x0f0f0f0f0f0f0f0f) << 4);
}

int main() {
  char* s = new char[N];
  scanf("%s",s);

  int n = strlen(s);
  int m = n/2;
  uint8_t* b = new uint8_t[m];

  hex_to_bin(s,b);

  for (int i=0; i<m; i++)
    // printf("%02x",b[i]);
    printf("%d ",b[i]);
  printf("\n");

  uint8_t* c = new uint8_t[m];
  swap_halves(m,b,c);

  char* t = new char[2*m+1];
  bin_to_hex(m,c,t);

  printf("%s\n",t);

  if (0x2143658709badcfe == swap2(0x1234567890abcdef))
    printf("OK\n");
  else
    printf("FAIL\n");

  return 0;
}

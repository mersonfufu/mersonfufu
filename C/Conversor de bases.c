/**
 * mersonfufu@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Prototypes
 */
int binary_to_decimal(char* binary);
char* binary_to_hexadecimal(char* binary);
int decimal_to_binary(int decimal);
char* decimal_to_hexadecimal(int decimal);
char* hexadecimal_to_binary(char* hexadecimal);
int hexadecimal_to_decimal(char* hexadecimal);

int main() {
  char input[20];
  int decimal, binary, hexadecimal;

  printf("Enter a decimal, binary (prefix 0b), or hexadecimal (prefix 0x) number: ");
  scanf("%s", input);

  if (input[0] == '0' && (input[1] == 'b' || input[1] == 'B')) {
    // Binary input
    binary = binary_to_decimal(input + 2);
    decimal = binary;
    char* hexadecimal = binary_to_hexadecimal(input + 2);

    printf("\n");
	//printf("Binary: %s\n", input + 2);
    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", hexadecimal);

    free(hexadecimal);
  } else if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
    // Hexadecimal input
    hexadecimal = hexadecimal_to_decimal(input + 2);
    decimal = hexadecimal;
    char* binary = hexadecimal_to_binary(input + 2);

    printf("\n");
	printf("Binary: %s\n", binary);
    printf("Decimal: %d\n", decimal);
    //printf("Hexadecimal: %s\n", input + 2);

    free(binary);
  } else {
    // Decimal input
    decimal = atoi(input);
    binary = decimal_to_binary(decimal);
    char* hexadecimal = decimal_to_hexadecimal(decimal);

    printf("\n");
	printf("Binary: %d\n", binary);
    //printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", hexadecimal);

    free(hexadecimal);
  }

  return 0;
}

/**
 * @brief Convert a binary number to decimal
 * @param binary The binary number to be converted
 * @return The decimal representation of the binary number
 */
int binary_to_decimal(char* binary) {
  int decimal = 0, base = 1;
  int length = strlen(binary);

  for (int i = length - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += base;
    }

    base *= 2;
  }

  return decimal;
}

/**
 * @brief Convert a binary number to hexadecimal
 * @param binary The binary number to be converted
 * @return The hexadecimal representation of the binary number
 */
char* binary_to_hexadecimal(char* binary) {
  int decimal = binary_to_decimal(binary);
  char* hexadecimal = decimal_to_hexadecimal(decimal);

  return hexadecimal;
}

/**
 * @brief Convert a decimal number to binary
 * @param decimal The decimal number to be converted
 * @return The binary representation of the decimal number
 */
int decimal_to_binary(int decimal) {
  int binary = 0, base = 1;

  while (decimal > 0) {
    binary += (decimal % 2) * base;
    decimal /= 2;
    base *= 10;
  }

  return binary;
}

/**
 * @brief Convert a decimal number to hexadecimal
 * @param decimal The decimal number to be converted
 * @return The hexadecimal representation of the decimal number
 */
char* decimal_to_hexadecimal(int decimal) {
  static char hexadecimal[10];
  int quotient = decimal;
  int remainder = 0;
  int index = 0;

  while (quotient != 0) {
    remainder = quotient % 16;

    if (remainder < 10) {
      hexadecimal[index] = remainder + '0';
    } else {
      hexadecimal[index] = remainder + 'A' - 10;
    }

    quotient /= 16;
    index++;
  }

  if (index == 0) {
    hexadecimal[index] = '0';
    index++;
  }

  hexadecimal[index] = '\0';
  strrev(hexadecimal);

  return hexadecimal;
}

/**
 * @brief Convert a hexadecimal number to binary
 * @param hexadecimal The hexadecimal number to be converted
 * @return The binary representation of the hexadecimal number
 */
char* hexadecimal_to_binary(char* hexadecimal) {
  int decimal = hexadecimal_to_decimal(hexadecimal);
  char* binary = decimal_to_binary(decimal);

  return binary;
}

/**
 * @brief Convert a hexadecimal number to decimal
 * @param hexadecimal The hexadecimal number to be converted
 * @return The decimal representation of the hexadecimal number
 */
int hexadecimal_to_decimal(char* hexadecimal) {
  int decimal = 0, base = 1;
  int length = strlen(hexadecimal);

  for (int i = length - 1; i >= 0; i--) {
    if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
      decimal += (hexadecimal[i] - '0') * base;
    } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
      decimal += (hexadecimal[i] - 'A' + 10) * base;
    } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
      decimal += (hexadecimal[i] - 'a' + 10) * base;
    }

    base *= 16;
  }

  return decimal;
}
/* Read a string from the user
Uses a function to count the number of vowels in the string.
The function must use pointers
The function returns the vowel count as an integer
(vowels: a, e, i, o, u - both uppercase and lowercase) */

#include <stdio.h>

int countVowels(char *str);

int main() {
	char word[50];
	
	printf("Enter a word:\n");
	fgets(word, 50, stdin);
	
	int vowels=countVowels(word);
	printf("Count of vowels: %d", vowels);
	return 0;
	
}

int countVowels(char *str) {
	int count=0;
	while(*str!='\0'){
		if(*str== 'a' ||*str== 'A' || *str== 'e'|| *str== 'E'|| *str== 'i' || *str== 'I'|| *str== 'o'|| 
		*str== 'O'|| *str== 'u'|| *str== 'U') {
			count++;
		}
		str++;
	}
	return count;
}


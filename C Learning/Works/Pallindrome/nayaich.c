#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ifAll9 = false;

void print(char* input, int len){
	if(ifAll9){
		len++;
		ifAll9 = false;
	}
	for(int i = 0; i < len; i++){
		printf("%d", input[i]);
	}
	printf("\n");
}

int isPalindrome(char* input, int len){
	int mid = len / 2;
	
	if(len % 2 == 0){
		int right = mid, left = mid - 1;
		
		while(right != len){
			if(input[right] != input[left]){
				return left;
			}
			right++;
			left--;
		}
	}
	else{
		for(int i = 1; i <= mid; i++){
			if(input[mid - i] != input[mid + i]){
				return mid - i;
			}
		}
	}
	return -1;
}

bool ifAllNine(char* input, int len){
	for(int i = 0; i < len; i++){
		if(input[i] != 9){
			return false;
		}
	}
	input[0] = 1;
	input[len] = 1;
	
	for(int i = 1; i < len; i++){
		//printf("%d\n", i);
		input[i] = 0;
	}
	ifAll9 = true;
	return true;
}

void ifPalindrome(char* input, int len){
	int mid = len / 2;
	
	if(input[0] == 9 && input[len - 1] == 9){
		if(ifAllNine(input, len)){
			return;
		}
	}
	
	if(len % 2 == 0){
		int right = mid, left = mid - 1;
		
		while(right != len){
			input[right]++;
			input[left]++;
			
			if(!(input[right] > 9)){
				return;
			}
			input[right] = 0;
			input[left] = 0;
			
			right++;
			left--;
		}	
		printf("Invalid Input\n");
	}
	else{
		input[mid]++;
		if(input[mid] != 10){
			return;
		}
		
		int right = mid + 1, left = mid - 1;
		input[mid] = 0;
		
		while(right != len){
			input[right]++;
			input[left]++;
			
			if(input[right] != 10){
				return;
			}
			input[right] = 0;
			input[left] = 0;
			right++;
			left--;
		}
	}
}

bool isGreater(char* copy, char* input, int len){
	for(int i = 0; i < len; i++){
		if(copy[i] > input[i]){
			return true;
		}
		else if(copy[i] < input[i]){
			return false;
		}
	}
}

void ifNotPalindrome(char* input, int len, int left){
	
	char copy[len];
	
	for(int i = 0; i < len; i++){
		copy[i] = input[i];
	}
	
	
	for(int i = 0; i <= left; i++){
		copy[(len - 1) - i] = copy[i];
	}
	
	bool ifGreater = isGreater(copy, input, len);
	
	for(int i = 0; i < len; i++){
		input[i] = copy[i];
	}
	
	
	if(ifGreater){
		return;
	}
	ifPalindrome(input, len);
}

void helper(char* input){
	int len = strlen(input);
	
	for(int i = 0; i < len; i++){
		input[i] -= '0';
	}
	int res = isPalindrome(input, len);
	
	//printf("res = %d\n", res);
	
	if (res == -1){
		ifPalindrome(input, len);
	}
	else{
		ifNotPalindrome(input, len, res);
	}
	
	print(input, len);
}

int main(){
	int inputNumber;
	char input[1000002];
	scanf("%d", &inputNumber);
	
	for(int i = 0; i < inputNumber; i++){
		scanf("%s", input);
		helper(input);
	}	
}




















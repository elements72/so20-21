#include <stdio.h>
#include <stdint.h>

union un{
	uint32_t i32;	//rappresentazione a 4byte
	uint8_t i8[4];	//rappresentazione usando un array
			//formato da locazioni di 1 byte
};

int main(){
	union un u;
	u.i32 = 1040;
	for(int i = 0; i < 4; i++){
		printf("%d  ", u.i8[i]);
	}
	printf("\n");
	return 0;

}

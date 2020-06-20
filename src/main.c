#include <stdio.h>

#define TAM_BUFFER 70
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

int convert_char_int (char c) {
	if(c=='A')
		return 0;
	else if(c=='B')
		return 1;
	else if(c=='C')
			return 2;
	else if(c=='D')
		return 3;
	else if(c=='E')
		return 4;
	else if(c=='F')
		return 5;
	else if(c=='G')
		return 6;
	else if(c=='H')
		return 7;
	else if(c=='I')
		return 8;
	else if(c=='J')
		return 9;
	else if(c=='K')
		return 10;
	else if(c=='L')
		return 11;
	else if(c=='M')
		return 12;
	else if(c=='N')
		return 13;
	else if(c=='O')
		return 14;
	else if(c=='P')
		return 15;
	else if(c=='Q')
		return 16;
	else if(c=='R')
		return 17;
	else if(c=='S')
		return 18;
	else if(c=='T')
		return 19;
	else if(c=='U')
		return 20;
	else if(c=='V')
		return 21;
	else if(c=='W')
		return 22;
	else if(c=='X')
		return 23;
	else if(c=='Y')
		return 24;
	else
		return 25;
}

char convert_int_char(int c){
	if(c==0)
		return 'A';
	else if(c==1)
		return 'B';
	else if(c==2)
			return 'C';
	else if(c==3)
		return 'D';
	else if(c==4)
		return 'E';
	else if(c==5)
		return 'F';
	else if(c==6)
		return 'G';
	else if(c==7)
		return 'H';
	else if(c==8)
		return 'I';
	else if(c==9)
		return 'J';
	else if(c==10)
		return 'K';
	else if(c==11)
		return 'L';
	else if(c==12)
		return 'M';
	else if(c==13)
		return 'N';
	else if(c==14)
		return 'O';
	else if(c==15)
		return 'P';
	else if(c==16)
		return 'Q';
	else if(c==17)
		return 'R';
	else if(c==18)
		return 'S';
	else if(c==19)
		return 'T';
	else if(c==20)
		return 'U';
	else if(c==21)
		return 'V';
	else if(c==22)
		return 'W';
	else if(c==23)
		return 'X';
	else if(c==24)
		return 'Y';
	else
		return 'Z';
}

char decod_letra(int x, int y) {
	int result;
	char letra;

	result=x-y;
	
	if(result<0)
		result=26+result;

	letra=convert_int_char(result);
	
	return letra;
}

int main() {

	char c;
	int i, j, tam_senha, x, y;
	j=0;
	i=0;
	tam_senha=12;

  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

	for (i=0; i!=TAM_BUFFER; i++){
		c=buffer_entrada[i];

		if(c==' ' || c=='!' || c=='.' || c=='\0' || c=='-'){
			buffer_saida[i]=c;
			if(j==tam_senha)
				j=1;
			else
				j++;
		} else if(c=='\n') {
			buffer_saida[i]='\0';
			if(j==tam_senha)
				j=1;
			else
				j++;
		} else {
			x=convert_char_int(buffer_entrada[i]);
		
			if(j==tam_senha){
				j=0;
				y=convert_char_int(senha[j]);
				j++;
			} else {
				y=convert_char_int(senha[j]);
				j++;
			}
		
			c=decod_letra(x, y);

			buffer_saida[i]=c;
		}
	}

	buffer_saida[i]='\0';
	
  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}

/**
 *  mersonfufu@gmail.com
 *  ultima update em 16:32 23/04/2021
 */
#include <stdio.h>

typedef struct Fight{
	int equip;
	int target;
	int diff;
} stFight;

int main(){
	int equip = 0, target = 0;
	stFight tabela[3][4];

	printf("Attacker and target values... ");
	scanf("%i %i", &equip, &target);

	for(int metal = 1; metal < 4; metal++)
		for(int chain = 0; chain < 4; chain++){
			tabela[metal - 1][chain].equip  = equip  + 300*metal + ((target + 300*chain)/2)*metal;
			tabela[metal - 1][chain].target = target + 300*chain;
			tabela[metal - 1][chain].diff   = tabela[metal - 1][chain].equip - tabela[metal - 1][chain].target;
		}

	for(int metal = 1; metal < 4; metal++){
		printf("\n");
		for(int chain = 0; chain < 4; chain++){
			printf(" -- ");
			if(!chain)
				printf("No Chain");
			else
				printf("Chain %02i", chain);
			printf(" --\t");
			if(chain == 3)
				printf("\n");
		}
		for(int chain = 0; chain < 4; chain++){
			printf("  METAL: %5i\t", tabela[metal - 1][chain].equip);
			if(chain == 3)
				printf("\n");
		}
		for(int chain = 0; chain < 4; chain++){
			printf("  TARGT: %5i\t", tabela[metal - 1][chain].target);
			if(chain == 3)
				printf("\n");
		}
		for(int chain = 0; chain < 4; chain++){
			printf("%9c------\t", 32);
			if(chain == 3)
				printf("\n");
		}
		for(int chain = 0; chain < 4; chain++){
			printf("  DIFF: %6i\t", tabela[metal - 1][chain].diff);
			if(chain == 3)
				printf("\n");
		}
	}

	return 0;
}
#include <stdio.h>
#include <string.h> 

// add the prototype of gets to avoid the warning extern function
char *gets(char *dst); 
typedef struct{
char fname[20];
char lname[20];
char nation[20];
float distance;
		} Jumper;

void load( char filename[10], Jumper jumper[]){
	// creating a temporary variable for holding a record 
	char fname[20];
	char lname[20];
	char nation[20];
	float distance;
	int counter;

	// declare a file pointer
	FILE *input= fopen(filename, "r+");

	//check if the file opened succesfully
    if (input==NULL)
		perror ("Error opening file");
    else{
		counter=0; 
		// continue in reading the file til the EOF
		while(!feof(input)){
			strcpy(fname," ");
			fscanf(input, "%s %s %s %e", fname,lname,nation,&distance);
			if(strcmp(fname,"FirstName")!=0){
				strcpy(jumper[counter].fname,fname);
				strcpy(jumper[counter].lname,lname);
				strcpy(jumper[counter].nation,nation);
				jumper[counter].distance=distance;
				counter++;
				}
				else{
					char buffer[100];
					fgets(buffer,100, input);
				}
		}
    fclose(input);
    }
}
void printJumper(Jumper j){
	printf("\nFirst Name: %s\nLast Name: %s\nNation: %s\nDistance: %.2f\n",j.fname, j.lname, j.nation, j.distance ); 
}

int main(int argc, char *argv[]){

Jumper myJumpers[40];
for(int i=0; i<40; i++)myJumpers[i].distance=-1;
char myFileName[10]="jump.txt"; 
	load(myFileName, myJumpers);
	
	float minJump;
	printf("enter the minimum jump distance ");
	scanf("%e", &minJump);
	//printf("%e", minJump);
	for(int i =0;i<40;i++){
	if(myJumpers[i].distance !=-1)
	if(myJumpers[i].distance >= minJump)
	printJumper(myJumpers[i]);
	}
	
	return 0;
}

fuck the shit
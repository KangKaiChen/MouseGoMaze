#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct Num{
	int num = -1;
	char column = '\0';
	Num* next;
	
};

char gch = '\0';
typedef Num* numpty;
int gnum = 0; // ���A�� 
int gnum2 = 0; // �k�A�� 


int getclevel(char text) { //��X�b��Ӹ̭����Ÿ��ƭ� 
        switch (text) {
            case '(':
                return 4;
                break;
            case '*':
            case '/':
                return  2;
                break;
            case '+':
            case '-':
                return 1;
                break;
            default:
                break;
        }
        
    }

int getslevel(char text) {   //��X�b���|�̭����Ÿ��ƭ� 

        switch (text) {
            case '(':
                return 0;
                break;
            case '*':
            case '/':
                return  2;
                break;
            case '+':
            case '-':
                return  1;
                break;
        }

    }
    
    
void Readnum( int &num, char &op , bool & run  ){ // Ū�Ʀr�P�᭱�Ÿ� 
	int num1 = 0;
    while ( gch >='0' && gch <= '9'  ){
    	num1 = num1*10 + gch - '0';
        cin.get( gch );
	    while(  gch ==' '  )  cin.get( gch ); 	
	    
	}
	
	num = num1;
        switch ( gch ) {
        	case '(':
            case ')':	
            case '*':
            case '/':
            case '+':
            case '-':
                op = gch;
                break;
            case '\n': 
			    break;   
            default:
            	cout << "Error 1" << gch <<" is not a legitimate character." <<endl;
                run = false;
                break;
        }
	
	
}    

void Read( numpty &num, bool & run  ){ // Ū��ꤤ�ǽT�{�������T�P���s 
	numpty head = NULL;
	numpty temp = NULL;
	int num1 = 0;
	char op = '\0';	
	bool haveop = true;
	while ( gch != '\n' && run  ) {
		cin.get( gch );
	    while(  gch ==' '  )   cin.get( gch );
	    //cout << gch << endl;
		if( gch >='0' && gch <= '9'  ) {
		  if (  !haveop  ){
		  	run = false;
            cout << "Error 3: there is one extra operand." << endl; 		  	
		  }
		  Readnum( num1, op, run );
		  //cout << num1->num;
		  if ( head == NULL  ){
		  	head = new Num();
		  	head->num = num1;
		  	temp = head;
		  	if( op != '\0'  ) {
		  	  temp->next = new Num();
		  	  temp = temp->next;
		  	  temp->column = op;
		    }
		    temp->next = NULL;
		  }
		  else{
            temp->next = new Num();
            temp = temp->next;
            temp->num = num1;
            haveop = true;
		  	if( op != '\0'  ) {
		  	  if( op == '('  )	{
		  	  	cout << "Error 3: there is one extra operand." << endl; 
				run = false;  
		      }		  		
		  	  if( op == ')'  )	{
		  	    haveop = false;
		  	    if ( gnum > gnum2   )
		          gnum2++;	
		        else{ 
		          cout << gnum << gnum2 <<"Error 2: there is one extra open parenthesis." << endl;
				  run = false;
			    }
		      }
		  	  temp->next = new Num();
		  	  temp = temp->next;
		  	  temp->column = op;
		    }
		    temp->next = NULL;		  	
		  }
	    }    
		else if( gch == '('   ) {
			gnum++;
		    if ( head == NULL   ){
		  	  head = new Num();
		  	  head->column = gch;
		  	  temp = head;
		    }
		    else{
		  	  temp->next = new Num();
		  	  temp = temp->next;
		  	  temp->column = gch;
		    }			
		    temp->next = NULL;
		}
		else if(  gch == '+' ||   gch == '-' || gch == '*' ||gch == '/'   ){
		    if ( !haveop   ){
		  	  temp->next = new Num();
		  	  temp = temp->next;
		  	  temp->column = gch;
		  	  haveop = true;
		  	  temp->next = NULL;
		    }
		    else{
              run = false;
              cout << "Error 3: there is one extra operator." << endl; 
		    }				
		}
		else {
			if ( gch != '\n'  ){
			  run = false;
			  cout << "Error 1" << gch <<" is not a legitimate character." <<endl;
			  break;
		    }
		}  
        op = NULL;

		if (!run) {
			while( gch != '\n'  ) cin.get( gch );
			
		}
		
	}
	
	if(  temp != NULL  ) {

	  if ( temp->num == -1 && temp->column != ')' && run ) {
	    run = false;
	    cout << "Error 3: there is one extra operator." << endl; ; 
      }
    }   
	num = head;
}

void comparestack(  numpty &stack, numpty head )  { // ����Ÿ��j�p�P��i���| 
	numpty temp = NULL;
	bool run = true;
	numpty del = NULL; // ����Ŷ� 
	do{	
	  if( stack == NULL  ){
	  	stack = new Num();
	  	stack->column = head->column;
	  	stack->next = NULL;
	  	run = false;
	  }
	  else if( getslevel( stack->column ) < getclevel( head->column )  ){
	  	temp = new Num();
	  	temp->column = head->column;
		temp->next = stack;  	  	
	  	stack = temp;
	  	run = false;
	  	break;
	  }	
	  else if( getslevel( stack->column ) == getclevel( head->column )  ){
        cout << stack->column << ",";
		stack->column = head->column;	
	  	run = false;
	  	break;
	  }	
	  
	  if( run  ) {
	  	if( stack->num == -1  )
	      cout << stack->column << ",";	
	    del = stack;  
	    stack = stack->next;
	    delete del;
		if( stack == NULL  ){
	  	  stack = new Num();
	  	  stack->column = head->column;
	  	  stack->next = NULL;
	  	  run = false;
	    }	
      } 
		
	}while( getslevel( stack->column ) >= getclevel( head->column ) && run  ) ;
	
	
	
	
}


void Print( numpty num  ) { // �p�G�J��Ʀr������X�Ÿ��h�O������X 
	numpty stack = NULL;
	numpty del = NULL; // ����Ŷ� 
	while ( num != NULL ) {
		if( num->num == -1 && num->column != ')'  )
		  comparestack( stack, num  );
		else if(  num->column ==  ')'  )  {
		  while( stack->column != '('  ){
		    cout << stack->column << ",";
		    stack = stack->next;
		
		
	      }
	      stack = stack->next;
			
			
			
		}
		else
		  cout << num->num << ",";  
		  
		del = num;
		num = num->next;		
		delete del ;
	}
	
	while( stack != NULL  ){
		if(  stack->num == -1 )
		  cout << stack->column << ",";
		del = stack;
		stack = stack->next;
		delete del;
		
	}
	
}
















int main(int argc, char** argv) {
	numpty num;
	char command ;
	numpty del = NULL;
	bool run = true;
	char ch;
	
	do {
	  command = -1;	
	  cout<< "* 0. Quit *";
      cout << endl << "* 1. Read*";
      cout << endl << "* 2. Read and print Postfix";
      cout << endl << "*******************************" << endl << "Command:";
      cin.get(command) ;
      cin.get(ch);
      
      
	  if( ( command == '1' || command == '2' )  && ch == '\n'  ) {
	  	cout << "Input:" ;
	    Read( num, run);
        if( gnum > gnum2   ) {
    	  run = false;
    	  cout << gnum << gnum2 <<"Error 2: there is one extra open parenthesis." << endl;
    	
    	
     	}
	    if( run && command == '1' )
    	  cout << "It is a legitimate infix expression." << endl;	    
	    if( run && command == '2' ) {
    	  cout << "Postfix expression:";	   	      	
		  Print( num );
		  cout << endl;
		
		
	    }
	    
	    if( !run) {
	      while (  num != NULL ) {
		  
	      del = num;
		  num = num->next;
		  delete del;	
	  }
	   }
   
	    
      }
      else if( command != '0' || ch != '\n'  ) {
      	  command = -1;
    	  cout << "Command does no exist." << endl;
		  while(  ch != '\n'  ) cin.get(ch);
      }  //
		  
	  num = NULL;
	  run = true;
	  gch = '\0';	
   } while (  command != '0'  ) ;
	return 0;
}

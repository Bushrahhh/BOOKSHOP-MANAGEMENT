//login authentication
//in this my goal is to make a user aka-> customer and  admin login platform
//sign-in and sing-up(register)
//they will be given 3 total chances to login
//if-else statement & switch statement will be used for implementing the conditions
//

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int option;

	//choosing options
	while(option!=3){
	cout<<"1 to Sign-in\n";
	cout<<"2 to register\n";
	cout<<"3 TO exit\n";
	cin>>option;
	
	switch(option)
	{
		case 1:{
 		    	//sign-in
 		    	//stored info
 		    	string ruser="z";
 	    		string rpassword="1234";
 	    		//user entering data 
 		    	string ruser1;
 	    		cout<<"Enter your user-name\n";
 		    	cin>>ruser1;
  	
 	    		string rpassword1;
 	    		cout<<"Enter your password\n";
 	    		cin>>rpassword1;
		    	
 		    	//checking if both data matches
			    	while(ruser1!=ruser)
	    	    	{	    	
		 	    	cout<<"WRONG\nKindly re-enter your username\n";
		 	    	cout<<"--------------\n";
     	 	    	cout<<"-username *  -\n";
         	    	cout<<"-password    -\n";
         	    	cout<<"--------------\n";
        	    	 cin>>ruser1;
	    	    	 };
	    		    
        	    	while(rpassword1!=rpassword)
			    	{
			    	cout<<"WRONG\nKindly re-enter your password\n";
		 	    	cout<<"--------------\n";
     	 	    	cout<<"-username    -\n";
         	    	cout<<"-password  * -\n";
         	    	cout<<"--------------\n";
         	    	cin>>rpassword1;
        	    	};
	    	        
        	    	//showing successful login
        	    	if(ruser1==ruser && rpassword1==rpassword)
        	    	{
        		    	cout<<"Sign-in Successful!";
			    	}
			    	break;}
    
		case 2:{
	    		//sign-up
	    		string user_name;
	    		cout<<"-----------------------\n";
	    		cout<<"-Enter your username  -\n";
        		cout<<"-                     -\n";
        		cout<<"-                     -\n";
        		cout<<"-                     -\n";
        		cout<<"-                     -\n";
        		cout<<"-                     -\n";
   	    		cout<<"-----------------------\n";
	    		cin>>user_name;
    		
	    		string password;
	    		cout<<"-----------------------------\n";
	    		cout<<"-Enter your username (done) -\n";
        		cout<<"-Enter your password        -\n";
        		cout<<"-                           -\n";
        		cout<<"-                           -\n";
        		cout<<"-                           -\n";
        		cout<<"-                           -\n";
   	    		cout<<"-----------------------------\n";
	    		cout<<"\n";
	    		cin>>password;		
    		
	    		string password1;
	    		cout<<"-------------------------------\n";
	    		cout<<"-Enter your username (done)  -\n";
        		cout<<"-Enter your password (done)  -\n";
    		    cout<<"-Re-enter your password      -\n";
        		cout<<"-                            -\n";
        		cout<<"-                            -\n";
        		cout<<"-                            -\n";
   	    		cout<<"------------------------------\n";
	    		cout<<"\n";
	    		cin>>password1;
	    		while(password1!=password)
	    		{
    			cout<<"WRONG\nKindly re-enter your password\n";
		    	cout<<"-------------------------------\n";
     	        cout<<"-Enter your username (done)  -\n";
            	cout<<"-Enter your password (done)  -\n";
                cout<<"-Re-enter your password      -\n";
                cout<<"-                            -\n";
                cout<<"-                            -\n";
                cout<<"-                            -\n";
   	            cout<<"------------------------------\n";

        		cin>>password1;
	        }
			break;}   
		case 3:{
			cout<<"Successfully exit\n";
			break;
		}
		default:
		{
			cout<<"Wrong option chosed\n";
			 }
}
    }
}

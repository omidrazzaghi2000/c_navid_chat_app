#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <stdlib.h> /*for use exit function*/
#include<time.h>
int Timer();
int  checkPhoneFormat(int num);
int checkUserPasswordDigits(int pass);
int checkUserPasswordmatching(int pass, int re_pass);
int phoneNumberExist(long long int first_num, long long int second_num);

int main()
{
	int m = 0;
	int commad_in_general_menu = 0;
	int commad_in_LogIn_menu = 0;
	long long int num1 = 0; 	// phone number of user 1 
	long long int num2 = 0;		// phone number of user 2 
	long long int num3 = 0;		// phone number of user 3 
	long long int check_number = 0;
	int check_pass = 0;
	int count_num1 = 0;  //number of digits  in num1
	int count_num2 = 0;		//number of digits  in num2
	int count_num3 = 0;		//number of digits  in num3
	int count_pass1 = 0;	//number of digits  in pass1
	int count_pass2 = 0;	//number of digits  in pass2
	int count_pass3 = 0;	//number of digits  in pass3
	int round = 1;			// in this program we have three rounds to get numbers
	int pass1 = 0; 			//password of user 1
	int pass2 = 0;			//password of user 2
	int pass3 = 0;			//password of user 3
	int pass11 = 0;			//re-enter password for user 1 to check if it is the same with pass 1.
	int pass22 = 0;			//re-enter password for user 2 to check if it is the same with pass 2.
	int pass33 = 0;			//re-enter password for user 3 to check if it is the same with pass 3.
	int pass111 = 0;		//declare to check if pass1 has less than 7 number of digits
	int pass222 = 0;		//declare to check if pass2 has less than 7 number of digits
	int pass333 = 0;		//declare to check if pass3 has less than 7 number of digits
	int wrongpass=0;
	int no_room = 0;
	int locked_login = 0;
	printf("               \x1b[42;1mwelcome to UTmessenger\n");
	printf("\x1b[0m");
	printf("\n");			//new line
	while (m == 0)
	{
		


		printf(" \x1b[43;1m***Please choose one of the following option  ***");
		printf("\x1b[0m");
		printf("\n");
		printf(" \x1b[44;1m *** 1 to signup  2 to Login  3 to Quit ***");
		printf("\x1b[0m");
		printf("\n");

		scanf_s("%d", &commad_in_general_menu);
		system("CLS");
		if (commad_in_general_menu != 1 && commad_in_general_menu != 2 && commad_in_general_menu != 3)
		{
			printf("Wrong commend!!\n");
			printf("Please Try Again ...\n");

			continue;
		}
		if (commad_in_general_menu == 1)  //	TO SIGNUP
		{
			while (m == 0)
			{

				int count_num1 = 0;
				int count_num2 = 0;
				int count_num3 = 0;


				if (num1 == 0)
				{
					printf("Enter your phone number : \n");

					printf("  \x1b[32;1mYou are the first user who sign in this program \n");
					printf("\x1b[0m");
					scanf_s("%lld", &num1);
					system("CLS");
					round = 1;

				}
				else if (num2 == 0)
				{
					int exist_check;
					printf("Enter your phone number : \n");
					printf("   \x1b[33;1m You are the second user who sign in this program \n");
					printf("\x1b[0m");
					scanf_s("%lld", &num2);
					round = 2;
					exist_check = phoneNumberExist( num1,num2);

					if (exist_check == 0) /*Check if there is the same two numbers*/
					{
						num2 = 0;
						printf("	  \x1b[32;1mPhone number exist please go to LogIn page \n");
						printf("\x1b[0m");
						printf("\n");	//new line
						round = 0;
						break;
					}


				}


				else if (num3 == 0)
				{
					int exist_check;
					printf("Enter your phone number : \n");
					printf("   \x1b[34;1mYou are the third user who sign in this program \n");
					printf("\x1b[0m");
					scanf_s("%lld", &num3);
					round = 3;
					exist_check = phoneNumberExist(num1, num3);

					if (exist_check == 0) /*Check if there is the same two numbers*/
					{
						num3 = 0;
						printf("	  \x1b[32;1mPhone number exist please go to LogIn page \n");
						printf("\x1b[0m");
						printf("\n");	//new line
						round = 0;
						break;
					}
					exist_check = phoneNumberExist(num2, num3);

					if (exist_check == 0) /*Check if there is the same two numbers*/
					{
						num3 = 0;
						printf("	  \x1b[32;1mPhone number exist please go to LogIn page \n");
						printf("\x1b[0m");
						printf("\n");	//new line
						round = 0;
						break;
					}


				}
				else
				{
					no_room = 1;
					printf(" No room  to join  our community :) \n");

					break;
				}

				if (round == 1)
				{
					int result;
					result = checkPhoneFormat(num1);
					if (result == 0)
					{
						num1 = 0;
						continue;
					}
					else if (result == 1)
					{
						break;
					}

				}
				if (round == 2)
				{
					int result;
					result = checkPhoneFormat(num2);
					if (result == 0)
					{

						num2 = 0;
						continue;
					}
					else if (result == 1)
					{
						break;
					}


				}
				if (round == 3)
				{
					int result;
					result = checkPhoneFormat(num3);
					if (result == 0)
					{
						num3 = 0;
						continue;
					}
					else if (result == 1)
					{
						break;
					}

				}
			}
			if (no_room == 1)  /*No room to sign anyone */
			{
				continue;
			}
			if (round == 0)
			{
				
				continue;
			}

			if (round == 3)
			{
				if (num3 == num2 || num3 == num1)   /*Check if there is the same two numbers*/
				{
					system("CLS");
					printf("	Phone number exist please go to LogIn page \n");
					continue;
				}

			}

			if (round == 1)
			{
				while (m == 0)	/*Password part*/
				{
					int check_digits_of_pass;
					
					printf("User 1 ! You should choose a password for your account\n");
					
					printf("Enter your password : \n");
					scanf_s("%d", &pass1);
					check_digits_of_pass = checkUserPasswordDigits(pass1);
					if (check_digits_of_pass == 0)
					{
						system("CLS");
						printf("Pass invalid.  password should be less than 7 digits \n");
						continue;
					}
					else if (check_digits_of_pass == 1)
					{
						int check_matching;
						printf("Re-Enter your password : \n");
						scanf_s("%d", &pass11);
						check_matching = checkUserPasswordmatching(pass1, pass11);
						if (check_matching == 0)
						{
							system("CLS");
							printf("Password does not match\n");
							continue;
						}
						else if (check_matching == 1)
						{
							system("CLS");
							printf("  Successful signup\n");
							printf("  Welcome to your program\n");
							break;
						}
					}
				}

			}
			if (round == 2)
			{
				while (m == 0)	/*Password part*/
				{
					int check_digits_of_pass;
					system("CLS");
					printf("User 2 ! You should choose a password for your account\n");
					
					printf("Enter your password : \n");
					
					scanf_s("%d", &pass2);
					
					check_digits_of_pass = checkUserPasswordDigits(pass2);
					if (check_digits_of_pass == 0)
					{
						system("CLS");
						printf("Pass invalid.  password should be less than 7 digits \n");
						continue;
					}
					else if (check_digits_of_pass == 1)
					{
						int check_matching;
						printf("Re-Enter your password : \n");
						scanf_s("%d", &pass22);
						check_matching = checkUserPasswordmatching(pass2, pass22);
						if (check_matching == 0)
						{
							system("CLS");
							printf("Password does not match\n");
							continue;
						}
						else if (check_matching == 1)
						{
							system("CLS");
							printf("  Successful signup\n");
							printf("  Welcome to your program\n");
							break;
						}
					}
				}

			}
			if (round == 3)
			{
				while (m == 0)	/*Password part*/
				{
					int check_digits_of_pass;
					system("CLS");
					printf("User 3 ! You should choose a password for your account\n");
					
					printf("Enter your password : \n");
					scanf_s("%d", &pass3);
					
					check_digits_of_pass = checkUserPasswordDigits(pass3);
					if (check_digits_of_pass == 0)
					{
						system("CLS");
						printf("Pass invalid.  password should be less than 7 digits \n");
						continue;
					}
					else if (check_digits_of_pass == 1)
					{
						int check_matching;
						printf("Re-Enter your password : \n");
						scanf_s("%d", &pass33);
						check_matching = checkUserPasswordmatching(pass3, pass33);
						if (check_matching == 0)
						{
							system("CLS");
							printf("Password does not match\n");
							continue;
						}
						else if (check_matching == 1)
						{
							system("CLS");
							printf("  Successful signup\n");
							printf("  Welcome to your program\n");
							break;
						}
					}
				}

			}



		}

		if (commad_in_general_menu == 2 && locked_login ==0)   // TO LOGIN
		{
		
			while (m == 0)
			{

				system("CLS");
				printf("	Please enter your phone number : \n");

				scanf_s("%lld", &check_number);
				printf("\n");
				
				if (check_number == num1) 	/*Enter number to logIn is num1*/

				{
					wrongpass = 1;
					while (m == 0)
					{
						
						printf("please enter your password : \n");
						scanf_s("%d", &check_pass);
						if (check_pass == pass1)
						{
							system("CLS");
							printf("Welcome to our program ;)  \n");
							break;
						}
						else
						{
							
							printf("%d  \n", wrongpass);
							//system("CLS");
							printf("Wrong password!!!\n");
							if (wrongpass == 3)
							{
								printf(" Too many attempts LogIn is locked\n");
								locked_login = 1;
								//Timer();
								break;
							}
							printf("please Try again .. \n");
							wrongpass ++;
							continue;
						}

					}

					break;

				}
				else if (check_number == num2)		/*Enter number to logIn is num2*/

				{
					while (m == 0)
					{
						
						printf("please enter your password : \n");
						scanf_s("%d", &check_pass);
						if (check_pass == pass2)
						{
							system("CLS");
							printf("Welcome to our program ;)  \n");
							break;
						}
						else
						{
							system("CLS");
							printf("Wrong password!!!\n");
							printf("please Try again .. \n");
							continue;
						}

					}
					break;


				}
				else if (check_number == num3)		/*Enter number to logIn is num3*/

				{
					while (m == 0)
					{
						system("CLS");
						printf("please enter your password : \n");
						scanf_s("%d", &check_pass);
						if (check_pass == pass3)
						{
							system("CLS");
							printf("Welcome to our program ;)  \n");
							break;
						}
						else
						{
							system("CLS");
							printf("Wrong password!!!\n");
							printf("please Try again .. \n");
							continue;
						}
					}
					break;

				}
				else
				{
					system("CLS");
					printf("The number does not exist \n");
					break;
				}


			}
			

		}
		else if(commad_in_general_menu == 2 && locked_login == 1)
		{
		Timer();
		locked_login=0;
		}


		if (check_number != num1 && check_number != num2 && check_number != num3) 	/*Check the enter number to be in users of program*/
		{
			continue;
		}


		if (commad_in_general_menu == 3)
		{
			system("CLS");
			printf("                 \x1b[41;1m See you later ;))");
			printf("\x1b[0m");
			exit(0);   /*close the program*/
		}
		if (wrongpass == 3)
		{
			continue;
		}
		while (m == 0)  /*Menu of program.After signup part and after LogIn part*/
		{
			
			printf("  1 . Send message\n");
			printf("  2 . Show messages\n");
			printf("  3 . Create channel\n");
			printf("  4 . Create group\n");
			printf("  5 . Log out\n");
			scanf_s("%d", &commad_in_LogIn_menu);
			if (commad_in_LogIn_menu != 1 && commad_in_LogIn_menu != 2 && commad_in_LogIn_menu != 3 && commad_in_LogIn_menu != 4 && commad_in_LogIn_menu != 5) /*Check the command if invlid*/
			{
				system("CLS");
				printf("\n");
				printf("Wrong commend\n");
				printf("Please Try Again ...\n");
				continue;
			}
			if (commad_in_LogIn_menu == 5) /*Log out*/
			{
				system("CLS");
				printf("\n");
				break;
			}
		}



		continue;
	}


}
int  checkPhoneFormat(int num)
{
	int count_num = 0;
	long long int temp = num; 		/*temp is abreviation of temporary*/
	while (temp != 0)
	{
		temp /= 10;
		count_num++;					 /*In this while we compute number of digits of num1*/
	}
	if (count_num != 10)
	{
		system("CLS");
		printf("wrong phone number format\n");
		printf("Plese try again\n");
		return 0;
		

	}
	else
	{
		return 1;
		
	}
}
int checkUserPasswordDigits(int pass)
{

	while (1)	/*Password part*/
	{

		int count_pass = 0;

		int substitute_pass = pass;

		while (substitute_pass != 0)
		{
			substitute_pass = substitute_pass / 10;
			count_pass++;				/*In this while we compute number of digits of pass1*/
		}

		if (count_pass > 6)
		{
			return 0;

		}
		else
		{
			return 1;

		}
	}
}
	
	



int checkUserPasswordmatching(int pass, int re_pass)
{
	if (pass != re_pass)
	{
		return 0;

	}
	else
	{
		return 1;

	}

}
int phoneNumberExist(long long int first_num, long long int second_num)
{
	if (first_num == second_num) /*Check if there is the same two numbers*/
	{

		return 0;
	}

}

int Timer()
{
	clock_t begin;
	int time_spent;
	unsigned int i;
	int former_time = 31;
	begin = clock();
	for (i = 0; 1; i++)
	{

		time_spent = (int)(clock() - begin) / CLOCKS_PER_SEC;
		int time_left = 30 - time_spent;

		if (time_left != former_time)
		{
			system("CLS");
			printf("LogIn is locked ! You should wait for %d seconds then you can try again \n", time_left);
			former_time = time_left;
		}
		if (time_spent >= 30)
		{
			system("CLS");
			
			return;
		}

	}
	return;
}

void Login(long long int num1,
	long long int num2,
	long long int num3,
	int pass1,
	int pass2,
	int pass3
	)
{
	while (1)
	{
		int check_number;
		
		system("CLS");
		printf("	Please enter your phone number : \n");

		scanf_s("%lld", &check_number);
		printf("\n");

		if (check_number == num1) 	/*Enter number to logIn is num1*/

		{

			int wrongpass = 1;
			while (1)
			{
				int check_pass;
				printf("please enter your password : \n");
				scanf_s("%d", &check_pass);
				if (check_pass == pass1)
				{
					system("CLS");
					printf("Welcome to our program ;)  \n");
					//break;
					return 1;
				}
				else
				{

					//printf("%d  \n", wrongpass);
					//system("CLS");
					printf("Wrong password!!!\n");
					if (wrongpass == 3)
					{
						printf(" Too many attempts LogIn is locked\n");
						//locked_login = 1;
						
						
						return -3;
						break;
					}
					printf("please Try again .. \n");
					wrongpass++;
					continue;
				}

			}

			break;

		}
		else if (check_number == num2)		/*Enter number to logIn is num2*/

		{
			while (1)
			{
				int check_pass;
				printf("please enter your password : \n");
				scanf_s("%d", &check_pass);
				if (check_pass == pass2)
				{
					system("CLS");
					printf("Welcome to our program ;)  \n");
					break;
				}
				else
				{
					system("CLS");
					printf("Wrong password!!!\n");
					printf("please Try again .. \n");
					continue;
				}

			}
			break;


		}
		else if (check_number == num3)		/*Enter number to logIn is num3*/

		{
			while (1)
			{
				int check_pass;
				system("CLS");
				printf("please enter your password : \n");
				scanf_s("%d", &check_pass);
				if (check_pass == pass3)
				{
					system("CLS");
					printf("Welcome to our program ;)  \n");
					break;
				}
				else
				{
					system("CLS");
					printf("Wrong password!!!\n");
					printf("please Try again .. \n");
					continue;
				}
			}
			break;

		}
		else
		{
			system("CLS");
			printf("The number does not exist \n");
			break;
		}


	}
}
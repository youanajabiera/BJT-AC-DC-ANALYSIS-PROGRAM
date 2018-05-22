#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/* Universal Variables Initiator for INPUT */
float RB=-1, RC=-1, RE=-1; /* Resistor at Base, Collector and Emitter */
float IB=-1, IC=-1, IE=-1; /* Current at Base, Collector and Emitter */
float VBB=-1, VCC=-1, VEE=-1; /* DC Voltage Input at Base, Collector and Emitter */
float VBE=-1, VCE=-1, VCB=-1; /* Transistor Voltage */
float BETHA=-1, ALPHA=-1; /* Amplifying Numbers */
float VCESAT=-1, ICSAT=-1, BETHASAT=-1; /* Saturated Numbers */
float re=-1, ro=-1, Zo=-1, Zi=-1, Zb=-1, Av=-1; /* AC Variable */
char slot[20]; /* Slot for marking */
char mark = 'X'; /* Initiator for replacing slot */
char again; /* Initiator for Repeating Function in Computation */

/* Main Function */
int main()
{
	password();
}

/* Password Function */
int password()
{
    const char passwording [15] = {"daskom01"};
    char pass [15];
    int log = 0;
    int x; 
    int repeat;
    for (repeat=1; repeat<=3; repeat++)
    {
    	log = 0;
    	
        system ("cls");
        FILE *file = fopen("Title.txt", "r");
    	char c;
   		 do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
        printf ("Number of Tries: %d/3", repeat);
        printf ("\n\n\n\t\t\tLogin to use the program...\n\n");
        printf ("\t\t\tEnter Password:\t");
        scanf ("%s", &pass);
        if (strcmp (pass,passwording)!=0)
        {
            log = 1;
        }
        else
        {
            for (x=0; x<strlen(pass); x++)
            {
                if (pass[x]!=passwording[x])
                {
                    log = 1;
                    break;
                }
            }
        }
        if (log == 0)
        {
            repeat = 3;
            menu();
        }
        else
        {
            printf ("Invalid Password");
        }
    }
}

/* Menu Function */
int menu()
{
	char pilihanmenu;
	system("cls");
    system("color F3");
    printf("\t\t================================\n");
    printf("\t\t||\tAnalysis of BJT       ||\n");
    printf("\t\t||\tDC and AC             ||\n");
    printf("\t\t================================\n");
    printf("\t\t||  [1] Start the program     ||\n");
    printf("\t\t||  [2] Features              ||\n");
    printf("\t\t||  [3] Guides                ||\n");
    printf("\t\t||  [4] Exit                  ||\n");
    printf("\t\t================================\n");
    printf("\t\tInput your choice : ");
    scanf("%s", &pilihanmenu);
    switch(pilihanmenu)
    {
    	case '1':
    		{
    			starttheprogram();
    			break;
			}
		case '2':
			{
				features();
				break;
			}
		case '3':
			{
				guides();
				break;
			}
		case '4':
			{
				system("cls");
				printf("\n\n\t\t================================\n");
    			printf("\t\t||\tThank You Very Much   ||\n");
    			printf("\t\t================================\n");
				exit(0);
			}
		default:
			{
				printf("\n\t\tValid Input: 1, 2, 3 or 4...");
				printf("\n\t\tPress any key to re-input...");
				getch();
				menu();
			}
	}
}

/* *******************************************************MAIN PROGRAM BLOCKS**************************************************************** */

/* Main Computation Function */
int starttheprogram()
{
	char choice;
	system ("cls");
    printf("\t\t================================\n");
    printf("\t\t||     [Start the program]    ||\n");
    printf("\t\t||     [ DC&AC  Analysis ]    ||\n");
    printf("\t\t================================\n");
    printf("\t\t||  [1] DC Analysis           ||\n");
    printf("\t\t||  [2] AC Analysis           ||\n");
    printf("\t\t================================\n");
    printf("\t\tInput your choice : ");
    scanf("%s",&choice);
    switch(choice)
        {
            case '1':
            {
            	BJTDC();
            	break;
            }
            case '2':
            {
                BJTAC();
                break;
            }
            default:
            {
                printf("\n\t\tValid Input: 1 or 2");
				printf("\n\t\tPress any key to re-input...");
				getch();
                starttheprogram();
            }
        }
}

/* BJTDC Menu Function */
int BJTDC()
{
	char BJTDCchoice;
	system("cls");
    printf("\t\t================================\n");
    printf("\t\t||        [BJT Analysis]      ||\n");
    printf("\t\t||        [DC Analysis ]      ||\n");
    printf("\t\t================================\n");
    printf("\t\t||  [1] Common Emitter        ||\n");
    printf("\t\t||  [2] Common Collector      ||\n");
    printf("\t\t||  [3] Common Base           ||\n");
    printf("\t\t================================\n");
    printf("\t\tInput your choice : ");
    scanf("%s",&BJTDCchoice);
    switch(BJTDCchoice)
        {
        case '1':
        	{
			dcemitter();
            break;
            }
        case '2':
            {
            dccollector();
            break;
            }
        case '3':
            {
            dcbase();
            break;
            }
        default:
            {
            printf("\n\t\tValid Input: 1, 2 or 3");
			printf("\n\t\tPress any key to re-input...");
			getch();
            BJTDC();
            break;
            }
        }
}

/* BJTAC Menu Function */
int BJTAC()
{
	char BJTACchoice;
	system("cls");
    printf("\t\t================================\n");
    printf("\t\t||        [BJT Analysis]      ||\n");
    printf("\t\t||        [AC Analysis ]      ||\n");
    printf("\t\t================================\n");
    printf("\t\t||  [1] Common Emitter        ||\n");
    printf("\t\t||  [2] Common Collector      ||\n");
    printf("\t\t||  [3] Common Base           ||\n");
    printf("\t\t================================\n");
    printf("\t\tInput your choice : ");
    scanf(" %s",&BJTACchoice);
    switch(BJTACchoice)
        {
        case '1':
        	{
			acemitter();
            break;
            }
        case '2':
            {
            accollector();
            break;
            }
        case '3':
            {
            acbase();
            break;
            }
        default:
            {
            printf("\n\t\tValid Input: 1, 2 or 3");
			printf("\n\t\tPress any key to re-input...");
			getch();
            BJTAC();
            break;
            }
        }
}

/* ************************************************************************ Formulas Function ****************************************************************************** */

/* Fixed Bias/Common Emitter DC Function */
int dcemitter()
{
    system("cls");
    printf("\t\t================================\n");
    printf("\t\t||        [DC Analysis ]      ||\n");
    printf("\t\t||       [Common Emitter]     ||\n");
    printf("\t\t================================\n");
    
    dcbiasfig1();
    
    printf("\t\t================================\n");
    printf("\t\t||           INPUT            ||\n");
    printf("\t\t================================\n");

    dcinput1();
    getch();
    printf("\n\n\n\t\t||--Computation Started--||\n");
    printf("Identified: \n");
    printf("Finding IB, IC, VCE...");
    IB = (VBB-VBE)/(RB);
    IC =  BETHA*IB;
    VCE = VCC-(IC*RC);
    printf("\n\n");
    printf ("\t\tIB         =   %f  A\n", IB);
    printf ("\t\tIC         =   %f  A\n", IC);
    printf ("\t\tVCE        =   %f  V\n", VCE);

    if (VCE<VCESAT)
    {
        printf ("\n\tBJT is saturated...\n\n");
        printf ("\tfinding saturated condition values...\n\n");
        ICSAT = (VCC-VCESAT)/RC;
        BETHASAT = ICSAT/IB;
        printf ("\tICSAT    =   %f  A\n", ICSAT);
        printf ("\tBETHASAT =   %f  \n", BETHASAT);
    }
    printf ("Press a to use this program again or else to back to main menu");
    again = getch();
    if (again == 'a')
    {
        system ("cls");
        dcemitter ();
    }
    else
    {
        system ("cls");
        menu();
    }
}

/* Fixed Bias/Common Emitter AC Function */
int acemitter()
{
	system("cls");
    printf("\t\t================================\n");
    printf("\t\t||        [AC Analysis ]      ||\n");
    printf("\t\t||       [Common Emitter]     ||\n");
    printf("\t\t================================\n");
    acbiasfig2();
    printf("\t\t================================\n");
    printf("\t\t||           INPUT            ||\n");
    printf("\t\t================================\n");

    acinput1();
    getch();
    printf("\n\n\n\t\t||--Computation Started--||\n");
    printf("Identified: \n");
    printf("Finding IB, IE, re, Zi, Zo, Av...");
    IB = (VBB-VBE)/(RB);
    IE =  (BETHA+1)*IB;
    re = 0.026/IE;
    printf("\n\n");
    printf ("\t\tIB         =   %f  A\n", IB);
    printf ("\t\tIC         =   %f  A\n", IC);
    printf ("\t\tVCE        =   %f  V\n", VCE);

    if (VCE<VCESAT)
    {
        printf ("\n\tBJT is saturated...\n\n");
        printf ("\tfinding saturated condition values...\n\n");
        ICSAT = (VCC-VCESAT)/RC;
        BETHASAT = ICSAT/IB;
        printf ("\tICSAT    =   %f  A\n", ICSAT);
        printf ("\tBETHASAT =   %f  \n", BETHASAT);
        Zi = RB*(BETHASAT*re)/((BETHASAT*re)+RB);
        Zo = RC*ro/(RC+ro);
        Av = -Zo/re;
        printf ("\t\tZi			=	%f	Ohm\n", Zi);
    	printf ("\t\tZo			=	%f	Ohm\n", Zo);
    	printf ("Av				=	%f	\n", Av);
    }
    else
    {
    	Zi = RB*(BETHA*re)/((BETHA*re)+RB);
    	Zo = RC*ro/(RC+ro);
    	Av = -Zo/re;
    	printf ("\t\tZi			=	%f	Ohm\n", Zi);
    	printf ("\t\tZo			=	%f	Ohm\n", Zo);
    	printf ("Av				=	%f	\n", Av);
	}
    printf ("Press a to use this program again or else to back to main menu");
    again = getch();
    if (again == 'a')
    {
        system ("cls");
        dcemitter ();
    }
    else
    {
        system ("cls");
        menu();
    }
}

/* Emitter Follower/Common Collector DC Function */
int dccollector()
{
    system("cls");
    printf("\t\t================================\n");
    printf("\t\t||        [DC Analysis ]      ||\n");
    printf("\t\t||     [Common Collector]     ||\n");
    printf("\t\t================================\n");
	dcbiasfig2();
    printf("\t\t================================\n");
    printf("\t\t||           INPUT            ||\n");
    printf("\t\t================================\n");

    dcinput2();
    getch();
    printf("\n\n\n\t\t||--Computation Started--||\n");
    printf("Identified: \n");
    printf("Finding IB, IC, IE, VCE...");
    IB = (VEE-VBE)/(RB+(BETHA+1)*RE);
    IC =  BETHA*IB;
    IE = (BETHA+1)*IB;
    VCE = VEE-(IE*RE);
    printf("\n\n");
    printf ("\t\tIB         =   %f  A\n", IB);
    printf ("\t\tIC         =   %f  A\n", IC);
    printf ("\t\tIE         =   %f  A\n", IE);
    printf ("\t\tVCE        =   %f  V\n", VCE);

    if (VCE<VCESAT)
    {
        printf ("\n\tBJT is saturated...\n\n");
        printf ("\tfinding saturated condition values...\n\n");
        ICSAT = (VEE-VCESAT)/(RE*(BETHA/BETHA+1));
        BETHASAT = ICSAT/IB;
        printf ("\tICSAT    =   %f  A\n", ICSAT);
        printf ("\tBETHASAT =   %f  \n", BETHASAT);
    }
    printf ("Press a to use this program again or else to back to main menu");
    again = getch();
    if (again == 'a')
    {
        system ("cls");
        dccollector();
    }
    else
    {
        system ("cls");
        menu();
    }
}

/* Emitter Follower/Common Collector AC Function */
int accollector()
{
    system("cls");
    printf("\t\t================================\n");
    printf("\t\t||        [AC Analysis ]      ||\n");
    printf("\t\t||     [Common Collector]     ||\n");
    printf("\t\t================================\n");
    acbiasfig2();
    printf("\t\t================================\n");
    printf("\t\t||           INPUT            ||\n");
    printf("\t\t================================\n");

    acinput2();
    getch();
    printf("\n\n\n\t\t||--Computation Started--||\n");
    printf("Identified: \n");
    printf("Finding IB, IE, re, Zi, Zo, Av...");
    IB = (VEE-VBE)/(RB+(BETHA+1)*RE);
    IE = (BETHA+1)*IB;
    re = 0.026/IE;
    VCE = VCC-(IE*RE);
    printf("\n\n");
    printf ("\t\tIB         =   %f  A\n", IB);
    printf ("\t\tIE         =   %f  A\n", IE);
    printf ("\t\tVCE        =   %f  V\n", VCE);

    if (VCE<VCESAT)
    {
        printf ("\n\tBJT is saturated...\n\n");
        printf ("\tfinding saturated condition values...\n\n");
        ICSAT = (VEE-VCESAT)/(RE*(BETHA/BETHA+1));
        BETHASAT = ICSAT/IB;
        printf ("\tICSAT    =   %f  A\n", ICSAT);
        printf ("\tBETHASAT =   %f  \n", BETHASAT);
        Zb = BETHASAT*re + (BETHASAT+1)*RE;
    	Zi = RB*(BETHASAT*re+(BETHASAT+1)*RE)/(RB+(BETHASAT*re+(BETHASAT+1)*RE));
    	Zo = RE*re/(RE+re);
		Av = ((BETHASAT+1)*RE/Zb/(1+RE/ro));
		printf ("\t\tZi			=	%f	Ohm\n", Zi);
    	printf ("\t\tZo			=	%f	Ohm\n", Zo);
    	printf ("Av				=	%f	\n", Av);
    }
    else
    {
    	Zb = BETHA*re + (BETHA+1)*RE;
    	Zi = RB*(BETHA*re+(BETHA+1)*RE)/(RB+(BETHA*re+(BETHA+1)*RE));
    	Zo = RE*re/(RE+re);
		Av = ((BETHA+1)*RE/Zb/(1+RE/ro));
		printf ("\t\tZi			=	%f	Ohm\n", Zi);
    	printf ("\t\tZo			=	%f	Ohm\n", Zo);
    	printf ("Av				=	%f	\n", Av);
	}
    printf ("Press a to use this program again or else to back to main menu");
    again = getch();
    if (again == 'a')
    {
        system ("cls");
        accollector();
    }
    else
    {
        system ("cls");
        menu();
    }
}

/* Common Base DC Function */
int dcbase()
{
    system("cls");
    printf("\t\t================================\n");
    printf("\t\t||        [DC Analysis ]      ||\n");
    printf("\t\t||        [Common Base ]      ||\n");
    printf("\t\t================================\n");
    dcbiasfig3();
    printf("\t\t================================\n");
    printf("\t\t||           INPUT            ||\n");
    printf("\t\t================================\n");

    dcinput3();
    getch();
    printf("\n\n\n\t\t||--Computation Started--||\n");
    printf("Identified: \n");
    printf("Finding IB, IC, IE, VCE, VCB...");
    IE = (VEE-VBE)/(RE);
    IB =  IE/(BETHA+1);
    IC = BETHA*IB;
    VCE = VEE+VCC-IE*(RC+RE);
    VCB = VCC-IC*RC;
    printf("\n\n");
    printf ("\t\tIE         =   %f  A\n", IE);
    printf ("\t\tIB         =   %f  A\n", IB);
    printf ("\t\tIC         =   %f  A\n", IC);
    printf ("\t\tVCE        =   %f  V\n", VCE);
    printf ("\t\tVCB        =   %f  V\n", VCB);

    if (VCE<VCESAT)
    {
        printf ("\n\tBJT is saturated...\n\n");
        printf ("\tfinding saturated condition values...\n\n");
        ICSAT = (VEE+VCC-VCE)/(BETHA/(BETHA+1)*(RC+RE));
        BETHASAT = ICSAT/IB;
        printf ("\tICSAT    =   %f  A\n", ICSAT);
        printf ("\tBETHASAT =   %f  \n", BETHASAT);
    }
    printf ("Press a to use this program again or else to back to main menu");
    again = getch();
    if (again == 'a')
    {
        system ("cls");
        dcbase ();
    }
    else
    {
        system ("cls");
        menu();
    }
}

/* Common Base AC Function */
int acbase()
{
    system("cls");
    IE = -1;
    VCE = -1;
    printf("\t\t================================\n");
    printf("\t\t||        [DC Analysis ]      ||\n");
    printf("\t\t||        [Common Base ]      ||\n");
    printf("\t\t================================\n");
    acbiasfig3();
    printf("\t\t================================\n");
    printf("\t\t||           INPUT            ||\n");
    printf("\t\t================================\n");

    acinput3();
    getch();
    printf("\n\n\n\t\t||--Computation Started--||\n");
    printf("Identified: \n");
	printf ("Finding IE, re, Zi, Zo, Av");
    IE = (VEE-VBE)/(RE);
    re = 0.026/IE;
    Zi = RE*re/(RE+re);
    Zo = RC;
    Av = RC/re;
    printf("\n\n");
    printf ("\t\tIE         =   %f  A\n", IE);
    printf ("\t\tre         =   %f  Ohm\n", re);
    printf ("\t\tZi         =   %f  Ohm\n", Zi);
    printf ("\t\tZo         =   %f  Ohm\n", Zo);
    printf ("\t\tAv         =   %f  \n", Av);

    printf ("Press a to use this program again or else to back to main menu");
    again = getch();
    if (again == 'a')
    {
        system ("cls");
        acbase ();
    }
    else
    {
        system ("cls");
        menu();
    }
}

/* ******************************************************************************INPUT FUNCTION**************************************************************** */
int input()
{
    printf ("\t\tMasukkan Input DC Emitter Berikut.\n");
    printf ("\t\tRB     (in Ohm)        =   ");scanf ("%f", &RB);
    printf ("\t\tRC     (in Ohm)        =   ");scanf ("%f", &RC);
    printf ("\t\tRE     (in Ohm)        =   ");scanf ("%f", &RE);
    printf ("\t\tIB     (in Ampere)     =   ");scanf ("%f", &IB);
    printf ("\t\tIC     (in Ampere)     =   ");scanf ("%f", &IC);
    printf ("\t\tIE     (in Ampere)     =   ");scanf ("%f", &IE);
    printf ("\t\tVBB    (in Volt)       =   ");scanf ("%f", &VBB);
    printf ("\t\tVCC    (in Volt)       =   ");scanf ("%f", &VCC);
    printf ("\t\tVEE    (in Volt)       =   ");scanf ("%f", &VEE);
    printf ("\t\tVBE    (in Volt)       =   ");scanf ("%f", &VBE);
    printf ("\t\tVCE    (in Volt)       =   ");scanf ("%f", &VCE);
    printf ("\t\tVCB    (in Volt)       =   ");scanf ("%f", &VCB);
    printf ("\t\tVCESAT (in Volt)       =   ");scanf ("%f", &VCESAT);
    printf ("\t\tBETHA                  =   ");scanf ("%f", &BETHA);
    identifier();
}

/* Fixed Bias DC Input Function */
int dcinput1()
{
    printf ("\t\tMasukkan Input DC Emitter Berikut.\n");
    printf ("\t\tRB     (in Ohm)        =   ");scanf ("%f", &RB);
    printf ("\t\tRC     (in Ohm)        =   ");scanf ("%f", &RC);
    printf ("\t\tVBB    (in Volt)       =   ");scanf ("%f", &VBB);
    printf ("\t\tVCC    (in Volt)       =   ");scanf ("%f", &VCC);
    printf ("\t\tVBE    (in Volt)       =   ");scanf ("%f", &VBE);
    printf ("\t\tVCESAT (in Volt)       =   ");scanf ("%f", &VCESAT);
    printf ("\t\tBETHA                  =   ");scanf ("%f", &BETHA);
    identifier();
}

/* Fixed Bias AC Input Function */
int acinput1()
{
	printf ("\t\tMasukkan Input DC Emitter Berikut.\n");
    printf ("\t\tRB     (in Ohm)        =   ");scanf ("%f", &RB);
    printf ("\t\tRC     (in Ohm)        =   ");scanf ("%f", &RC);
    printf ("\t\tVBB    (in Volt)       =   ");scanf ("%f", &VBB);
    printf ("\t\tVCC    (in Volt)       =   ");scanf ("%f", &VCC);
    printf ("\t\tVBE    (in Volt)       =   ");scanf ("%f", &VBE);
    printf ("\t\tVCESAT (in Volt)       =   ");scanf ("%f", &VCESAT);
    printf ("\t\tBETHA                  =   ");scanf ("%f", &BETHA);
    printf ("\t\tro		(in Ohm)		=	");scanf ("%f", &ro);
    identifier();
}

/* Emitter Follower DC Input Function */
int dcinput2()
{
    printf ("\t\tMasukkan Input DC Collector Berikut.\n");
    printf ("\t\tRB     (in Ohm)        =   ");scanf ("%f", &RB);
    printf ("\t\tRE     (in Ohm)        =   ");scanf ("%f", &RE);
    printf ("\t\tIB     (in Ampere)     =   ");scanf ("%f", &IB);
    printf ("\t\tVEE    (in Volt)       =   ");scanf ("%f", &VEE);
    printf ("\t\tVBE    (in Volt)       =   ");scanf ("%f", &VBE);
    printf ("\t\tVCE    (in Volt)       =   ");scanf ("%f", &VCE);
    printf ("\t\tVCESAT (in Volt)       =   ");scanf ("%f", &VCESAT);
    printf ("\t\tBETHA                  =   ");scanf ("%f", &BETHA);
    identifier();
}

/* Emitter Follower AC Input Function */
int acinput2()
{	
	printf ("\t\tMasukkan Input AC Collector Berikut.\n");
    printf ("\t\tRB     (in Ohm)        =   ");scanf ("%f", &RB);
    printf ("\t\tRE     (in Ohm)        =   ");scanf ("%f", &RE);
    printf ("\t\tVCC    (in Volt)       =   ");scanf ("%f", &VEE);
    printf ("\t\tVBE    (in Volt)       =   ");scanf ("%f", &VBE);
    printf ("\t\tVCESAT (in Volt)       =   ");scanf ("%f", &VCESAT);
    printf ("\t\tBETHA                  =   ");scanf ("%f", &BETHA);
    printf ("\t\tro		(in Ohm)		=	");scanf ("%f", &ro);
    identifier();
}

/* Common Base DC Input Function */
int dcinput3()
{
    printf ("\t\tMasukkan Input DC Base Berikut.\n");
    printf ("\t\tRC     (in Ohm)        =   ");scanf ("%f", &RC);
    printf ("\t\tRE     (in Ohm)        =   ");scanf ("%f", &RE);
    printf ("\t\tIE     (in Ampere)     =   ");scanf ("%f", &IE);
    printf ("\t\tVCC    (in Volt)       =   ");scanf ("%f", &VCC);
    printf ("\t\tVEE    (in Volt)       =   ");scanf ("%f", &VEE);
    printf ("\t\tVBE    (in Volt)       =   ");scanf ("%f", &VBE);
    printf ("\t\tVCE    (in Volt)       =   ");scanf ("%f", &VCE);
    printf ("\t\tVCB    (in Volt)       =   ");scanf ("%f", &VCB);
    printf ("\t\tVCESAT (in Volt)       =   ");scanf ("%f", &VCESAT);
    printf ("\t\tBETHA                  =   ");scanf ("%f", &BETHA);
    identifier();
}

/* Common Base AC Input Function */
int acinput3()
{
    printf ("\t\tMasukkan Input AC Base Berikut.\n");
    printf ("\t\tRC     (in Ohm)        =   ");scanf ("%f", &RC);
    printf ("\t\tRE     (in Ohm)        =   ");scanf ("%f", &RE);
    printf ("\t\tVCC    (in Volt)       =   ");scanf ("%f", &VCC);
    printf ("\t\tVEE    (in Volt)       =   ");scanf ("%f", &VEE);
    printf ("\t\tVBE    (in Volt)       =   ");scanf ("%f", &VBE);
    printf ("\t\tALPHA                  =   ");scanf ("%f", &ALPHA);
    printf ("\t\tro		(in Ohm)		=	");scanf ("%f", &ro);
    identifier();
}

/* Missings Identifier Function */
int identifier()
{
	memset(slot,' ',sizeof(slot));
	if (RB == -1)
	{
		slot [0] = mark;
	}
	if (RC == -1)
	{
		slot [1] = mark;
	}
	if (RE == -1)
	{
		slot [2] = mark;
	}
	if (IB == -1)
	{
		slot [3] = mark;
	}
	if (IC == -1)
	{
		slot [4] = mark;
	}
	if (IE == -1)
	{
		slot [5] = mark;
	}
	if (VBB == -1)
	{
		slot [6] = mark;
	}
	if (VCC == -1)
	{
		slot [7] = mark;
	}
	if (VEE == -1)
	{
		slot [8] = mark;
	}
	if (VBE == -1)
	{
		slot [9] = mark;
	}
	if (VCE == -1)
	{
		slot [10] = mark;
	}
	if (VCB == -1)
	{
		slot [11] = mark;
	}
	if (BETHA == -1)
	{
		slot [12] = mark;
	}
	if (VCESAT == -1)
	{
		slot [13] = mark;
	}
	if (ro == -1)
	{
		slot [14] = mark;
	}
	identab();
}

/* Mapping Missing Function */
int identab()
{
	printf ("________________________________________________________________________________");
	printf ("\t\t[TABLE OF 'MISSING']\n");
	printf ("\t\t ______________\n");
	printf ("\t\t| RB | RC | RE |\n");
	printf ("\t\t| %c  | %c  | %c  |\n", slot[0],slot[1],slot[2]);
	printf ("\t\t|____|____|____|\n");
	printf ("\t\t| IB | IC | IE |\n");
	printf ("\t\t| %c  | %c  | %c  |\n", slot[3],slot[4],slot[5]);
	printf ("\t\t|____|____|____|\n");
	printf ("\t\t|VBB |VCC |VEE |\n");
	printf ("\t\t| %c  | %c  | %c  |\n", slot[6],slot[7],slot[8]);
	printf ("\t\t|____|____|____|\n");
	printf ("\t\t|VBE |VCE |VCB |\n");
	printf ("\t\t| %c  | %c  | %c  |\n", slot[9],slot[10],slot[11]);
	printf ("\t\t|____|____|____|\n");
	printf ("\t\t|    BETHA     |\n");
	printf ("\t\t|      %c       |\n", slot[12]);
	printf ("\t\t|______________|\n");
	printf ("\t\t|    VCE.SAT   |\n");
	printf ("\t\t|      %c       |\n", slot[13]);
	printf ("\t\t|______________|\n");
	printf ("\t\t|      ro      |\n");
	printf ("\t\t|      %c       |\n", slot[14]);
	printf ("\t\t|______________|\n");
	return 0;
}

/* **************************************************************************FIGURES FUNCTION****************************************************************************** */

/* Fixed Bias DC Figures Function */
int dcbiasfig1()
{
    FILE *file = fopen("DC Fixed Bias.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
}

/* Emitter Follower DC Figures Function */
int dcbiasfig2()
{
    FILE *file = fopen("DC Emitter Follower.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
}

/* Common Base DC Figures Function */
int dcbiasfig3()
{
    FILE *file = fopen("DC Common Base.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
}

/* Fixed Bias AC Figures Function */
int acbiasfig1()
{
    FILE *file = fopen("AC Fixed Bias.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
}

/* Emitter Follower AC Figures Function */
int acbiasfig2()
{
    FILE *file = fopen("AC Emitter Follower.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
}

/* Common Base AC Figures Function */
int acbiasfig3()
{
    FILE *file = fopen("AC Common Base.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
}

/* *********************************************************** COMPLEMENTARY BLOCKS *************************************************************** */
/* Features List Function */
int features()
{
    system ("cls");
    FILE *file = fopen("Features.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
    getch();
    menu();
}

/* Guides Function */
int guides()
{
    system ("cls");
    FILE *file = fopen("Guides.txt", "r");
    char c;
    do
    {
        c = fgetc(file);
        printf ("%c", c);
    }
    while (c != EOF);
    fclose(file);
    printf("\n");
    getch();
    menu();
}

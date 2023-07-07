#include <stdio.h>

int main()
{
    int sum = 0,n,t;
    int s1,s2,s3,s4,s5,s6,s7;
    s1 = s2 = s3 = s4 = s5 = s6 = s7 = 1;
    for(int i=0;i<7;i++)
    {
        printf("Enter day of week (1 for Monday 2 for Tuesday and so on)\n");
        scanf("%d",&n);
        
        switch(n)
        {
            case 1:{
            printf("Enter number of vaccinations done:\n");
            scanf("%d",&t);
            sum+= t;
            
            if(s1 != 1)
            i--;
            
            s1++;
            break;
            }

            case 2:{
            printf("Enter number of vaccinations done:\n");
            scanf("%d",&t);
            sum+= t;

            if(s2 != 1)
            i--;
            
            s2++;
            break;
            }

            case 3:{
            printf("Enter number of vaccinations done:\n");
            scanf("%d",&t);
            sum+= t;

            if(s3 != 1)
            i--;
            
            s3++;
            break;
            }

            case 4:{
            printf("Enter number of vaccinations done:\n");
            scanf("%d",&t);
            sum+= t;

            if(s4 != 1)
            i--;
            
            s4++;
            break;
            }

            case 5:{
            printf("Enter number of vaccinations done:\n");
            scanf("%d",&t);
            sum+= t;

            if(s5 != 1)
            i--;
            
            s5++;
            break;
            }

            case 6:{
            printf("Enter number of vaccinations done:\n");
            scanf("%d",&t);
            sum+= t;

            if(s6 != 1)
            i--;
            
            s6++;
            break;
            }

            case 7:{
            printf("Enter number of vaccinations done:\n");
            scanf("%d",&t);
            sum+= t;

            if(s7 != 1)
            i--;
            
            s7++;
            break;
            }
        
            default:
            printf("Galat\n");
        }
    }
    
    printf("Total vaccinations done: %d",sum);
    return 0;
}
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int i=0,g=0;
struct num{
    char name[100]; //����
    char sex[100];//�Ա�
    char age[50];//����
    char work[200];//������λ
    char workphone[200];//�����绰
    char phone[200];//�ֻ�
    char sort[100];//���
    char mail[200];//����
};
void login()    //��¼
{
    int j;
    system("type ascii.txt");
    for(j=0;j<3;j++)
    {
        int i=0;
        char c_usr[10]="student",c_pwd[10]="pass1234";    //��ȷ�û�������
        char usr[10],pwd[10];    //�û�����
        printf("�������û�����\n");
        gets(usr);
        printf("���������룺\n");
        while (i<10)
        {

            pwd[i] = getch();
            if(pwd[i]=='\r')
                break;
            if(pwd[i]!='\b')
            {
                i++;
                printf("*");//��ʾ*��
            }
            else
            {
                i--;
                printf("\b \b");	//�˸�
            }
        }
        pwd[i]='\0';
        if(strcmp(c_usr, usr)==0)
            if(strcmp(c_pwd, pwd)==0)
            {
                printf("��¼�ɹ�\n");
                system("pause");
                system("cls");
                break;
            }
            else
                printf("�������\n");
        else
        {
            printf("�û�������\n");
        }

    }
    if(j>2)
    {
        printf("�����������ﵽ����\n");
        exit(0);
    }
}
void input(struct num  person[]) {    //����
    int j,x;   //xΪ�����ֻ���λ����jΪѭ������
    char o[5];  //�����Ƿ������ϵ�˵ı���
    while (1) {
        printf("�Ƿ�Ҫ�����ϵ��:");
        scanf("%s", &o);
        if (strcmp(o,"��")==0) {
            printf("����:");
            scanf("%s", person[i].name);
            for (j = 0; j <i; j++)      //�ж���ϵ���Ƿ��ظ�
                if (strcmp(person[i].name,person[j].name)==0)
                {printf("��ϵ���Ѵ���!\n");
                    system("pause");
                    return;}
            printf("�Ա�:");
            scanf("%s", person[i].sex);
            if(strcmp(person[i].sex,"��")==0||strcmp(person[i].sex,"Ů")==0) //�ж��Ա���ȷ
                printf("����:");
            else
            {printf("��������ȷ���Ա�!\n");
                system("pause");
                return 0;}
            scanf("%s", person[i].age);
            printf("������λ:");
            scanf("%s", person[i].work);
            printf("�����绰:");
            scanf("%s", person[i].workphone);
            printf("�ֻ�:");
            scanf("%s", person[i].phone);
            x=strlen(person[i].phone);
            if(x<11||x>11)    //�ж�λ��
            {printf("��������ȷ���ֻ����룡\n");
                system("pause");
                return 0;}
            printf("���:");
            scanf("%s", person[i].sort);
            printf("����:");
            scanf("%s", person[i].mail);
            i++;
        }
        else
        {printf("���������!\n");
            system("pause");
            break;
            }
    }
}
void chaxun1(struct num person[]) {     //��������ѯ
    int j;
    char name[20];   //���������ѯ������
    printf("��������Ҫ��ѯ����ϵ�˵�����:");
    gets(name);
    for (j = 0; j <i; j++)
        if (strcmp(name,person[j].name)==0)
            break;
    if(j>=i)
        printf("�޸���ϵ��\n");
    else
    {printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
               person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}
}
void chaxun2(struct num person[]) {    //�õ绰�����ѯ
    int j;
    char phone[20];
    printf("��������Ҫ��ѯ����ϵ�˵��ֻ�����:");
    gets(phone);
    for (j = 0; j <i; j++)
        if (strcmp(phone,person[j].phone)==0)
            break;
    if(j>=i)
        printf("�޸���ϵ��\n");
    else
    {       printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
               person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}
}
void count(struct num person[])     //ͳ��
{
    int boy=0,girl=0,sum=0,j,nel=0;
    for(j=0;j<i;j++)
    {
        if(strcmp(person[j].sex,"��")==0)
            boy++;
        else if(strcmp(person[j].sex,"Ů")==0)
            girl++;
    }
    sum=boy+girl;
    printf("-------------------------------\n");
    printf("|      ����������%d��          |\n",boy);
    printf("|-----------------------------|\n");
    printf("|      Ů��������%d��          |\n",girl);
    printf("|-----------------------------|\n");
    printf("|       ��������%d��	      |\n",sum);
    printf("-------------------------------\n");
}

void xiugai(struct num person[]){     //�޸���Ϣ
    int j,x;    //jΪѭ��������xΪ���뽫Ҫ�޸ĵĲ���
    char name[200];
    printf("��������Ҫ�޸���Ϣ������:");
    gets(name);
    for(j=0;j<i;j++)
        if(strcmp(person[j].name,name)==0)
		break;
		if(j<i)
		{printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
		person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}

    if(strcmp(person[j].name,name)!=0)
        printf("�޸���ϵ��!\n");
    else
    {
        printf("��ѡ����Ҫ�޸ĵĲ���:\n");
        printf("------------------------\n");
        printf("|       1-->����       |\n");
        printf("|       2-->�Ա�       |\n");
        printf("|       3-->����       |\n");
        printf("|       4-->�����ص�   |\n");
        printf("|       5-->�����绰   |\n");
        printf("|       6-->�ֻ�       |\n");
        printf("|       7-->���       |\n");
        printf("|       8-->����       |\n");
        printf("-------------------------\n");
        scanf("%d",&x);
        switch(x){
            case 1:printf("��������Ҫ�޸ĵ�����:\n");
                scanf("%s",person[j].name);
                printf("�޸ĳɹ�!\n");
                break;
            case 2:printf("��������Ҫ�޸ĵ��Ա�:\n");
                scanf("%s",person[j].sex);
                printf("�޸ĳɹ�!\n");
                break;
            case 3:printf("��������Ҫ�޸ĵ�����:\n");
                scanf("%s",person[j].age);
                printf("�޸ĳɹ�!\n");
                break;
            case 4:printf("��������Ҫ�޸ĵĹ����ص�:\n");
                scanf("%s",person[j].work);
                printf("�޸ĳɹ�!\n");
                break;
            case 5:printf("��������Ҫ�޸ĵĹ����绰:\n");
                scanf("%s",person[j].workphone);
                break;
            case 6:printf("��������Ҫ�޸ĵ��ֻ�����:\n");
                scanf("%s",person[j].phone);
                printf("�޸ĳɹ�!\n");
                break;
            case 7:printf("��������Ҫ�޸ĵ����:\n");
                scanf("%s",person[j].sort);
                break;
            case 8:printf("��������Ҫ�޸ĵ�����:\n");
                scanf("%s",person[j].mail);
                printf("�޸ĳɹ�!\n");
                break;
            default:printf("��������޸�ʧ��\n");}
		printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
		person[j].workphone,person[j].phone, person[j].sort, person[j].mail);

    }
}
void xianshi(struct num person[]){       //��������˳����ʾ
    int j,n;
    struct num empty;
        for (j = 0; j < i ; j++)
            for(n=j+1;n<i;n++) {
            if (strcmp(person[j].name, person[n].name) > 0)
            {
                empty = person[n];
                person[n] = person[j];
                person[j] = empty;
            }
    }
    printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
    for(j=0;j<i;j++)
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
               person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}


void shanchu(struct num person[])
{
    char f_name[50];
    char jueze[100];
    int j,k;
    printf("����������ɾ����ϵ�˵�������");
    scanf("%s",f_name);
    for(j=0;j<i;j++)
    {
        if(strcmp(person[j].name,f_name)==0)
        {
            printf("����ȷ���ǲ��Ǹ���ϵ�ˣ�\n");
            printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
            printf("�Ƿ����ɾ����\n");
            scanf("%s",&jueze);
            if(strcmp(jueze,"��")==0)
            {
                for(k=j;k<i-1;k++)
                    person[k]=person[k+1];
                i--;
                printf("ɾ���ɹ���\n");
                }

            else
                printf("���������!\n");
                break;
        }


    }
    if(j>=i-1)
    printf("�޸���ϵ��!\n");
}
void leibie(struct num person[])
{
    int j,k=0,l=0,z=0,x=0,v=0,s=0,nn=0;
    printf("=====================================================================================\n");
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"����")==0)
        {	nn++;
            if(k==0&&strcmp(person[j].sort,"����")==0)
            {
                k++;
                printf("����:\n");
                printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");	}
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
        }
    }
    printf("���˹���%dλ��ϵ��\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    printf("\n");
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"����")==0)
        {
            nn++;
            if(l==0&&strcmp(person[j].sort,"����")==0)
            {
                l++;
                printf("����:\n");
                printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
            }
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
        }
    }
    printf("���ѹ���%dλ��ϵ��\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"��ʦ")==0)
        {
            nn++;
            if(z==0&&strcmp(person[j].sort,"��ʦ")==0)
            {	z++;
                printf("��ʦ��\n");
                printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
            }
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);

        }
    }
    printf("��ʦ����%dλ��ϵ��\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"ͬ��")==0)
        {
            nn++;
            if(x==0&&strcmp(person[j].sort,"ͬ��")==0)
            {
                x++;
                printf("ͬ�£�\n");
                printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
            }
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);

        }
    }
    printf("ͬ�¹���%dλ��ϵ��\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    for(j=0;j<i;j++)
    {
        if(strcmp(person[j].sort,"ͬ��")==0)
            v++;
        else if(strcmp(person[j].sort,"��ʦ")==0)
            v++;
        else if(strcmp(person[j].sort,"����")==0)
            v++;
        else if(strcmp(person[j].sort,"����")==0)
            v++;
            //if(strcmp(person[j].sort,"ͬ��")==0&&strcmp(person[j].sort,"��ʦ")==0&&strcmp(person[j].sort,"����")==0&&strcmp(person[j].sort,"����")==0)
        else if(v==j&&s==0){
            s++;
            v++;
            nn++;
            printf("������\n");
            printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);}
        else if(v==j){
            nn++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
        }
    }
    printf("��������%dλ��ϵ��\n",nn);
    printf("\n");
    printf("=====================================================================================\n");
}
void menu()
{
    system("cls");
    system("type ascii.txt");
    printf("\t\t\t\t\t\t\t\t\t -------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t |------------Address Book-----------| \n");
    printf("\t\t\t\t\t\t\t\t\t |-----------------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t |      1->������µ���ϵ��          |\n");
    printf("\t\t\t\t\t\t\t\t\t |      2->�޸�������ϵ�˵���Ϣ      |\n");
    printf("\t\t\t\t\t\t\t\t\t |      3->ɾ��ĳ����ϵ��            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      4->��ʾ������ϵ����Ϣ        |\n");
    printf("\t\t\t\t\t\t\t\t\t |      5->��ѯ��ϵ����Ϣ            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      6->ͳ����Ů��ϵ�˺�������    |\n");
    printf("\t\t\t\t\t\t\t\t\t |      7->��ȡ��ϵ����Ϣ            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      8->������ϵ����Ϣ            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      9->������                    |\n");
    printf("\t\t\t\t\t\t\t\t\t |      0->�˳�                      |\n");
    printf("\t\t\t\t\t\t\t\t\t ------------------------------------- \n");}

void file_write(struct num person[])  //д��
{
    int j;
    FILE *data;
    data=fopen("data.csv","w");
    if(data==NULL)
    {
        printf("�ļ��޷���\n");
        exit(0);
    }
    for(j=0;j<i;j++)
    {
        fprintf(data,"%s \t",person[j].name);
        fprintf(data,"%s \t",person[j].sex);
        fprintf(data,"%s \t",person[j].age);
        fprintf(data,"%s \t",person[j].work);
        fprintf(data,"%s \t",person[j].workphone);
        fprintf(data,"%s \t",person[j].phone);
        fprintf(data,"%s \t",person[j].sort);
        fprintf(data,"%s\n",person[j].mail);
    }
    fclose(data);
    printf("����ɹ�!\n");
}

void file_read(struct num person[])   //��ȡ
{
    int j,line=0;
    char k;
    FILE *data;
    data=fopen("data.csv","r");
    data=fopen("data.csv","r");
    while(!feof(data)){
        fscanf(data,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",person[i].name,person[i].sex,person[i].age,person[i].work,person[i].workphone,
               person[i].phone,person[i].sort,person[i].mail);
        i++;
    }
    i--;
    printf("��ȡ�ɹ�\n");
    fclose(data);
}
void henmingdan(struct num person[],struct num hmd[]){			//������
		int x,j,c;
		char name[50];
		printf("����������ѡ��:\n");
        printf("------------------------------\n");
        printf("|       1-->���������       |\n");
        printf("|       2-->�Ƴ�������       |\n");
        printf("|       3-->�鿴��������ϵ�� |\n");
        printf("|       4-->����             |\n");
        printf("|       5-->��ȡ             |\n");
        printf("|       0-->�˳�             |\n");
        printf("------------------------------\n");
		scanf("%d",&x);
		if(x==1)
		{system("color 0C");
		printf("������һ�����֣��������������\n");
			getchar();
			gets(name);
		for(j=0;j<i;j++)
			if(strcmp(name,person[j].name)==0)
				break;
		if(j<i)
			{
			hmd[g]=person[j];	
			g++;
			printf("����������ɹ�\n");
			for(j=i;j<i-1;j++)
				{
				person[j]=person[j+1];
				}
			i--;	
			}
		else
			printf("û�и���ϵ��\n");
		system("pause");
		}
		if(x==2)
		{system("color 0D");
			printf("������һ�����֣�����ȡ��������\n");
			getchar();
			gets(name);
			for(c=0;c<g;c++)
			if(strcmp(name,hmd[c].name)==0)
				break;
			if(c<g)
			{
					person[i]=person[c];
					i++;
					printf("ȡ���������ɹ�\n");
					system("pause");
				for(j=c;j<g-1;j++)
					hmd[j]=hmd[j+1];
					g--;
			}
			else
			{	printf("��������û�и���ϵ��\n");
			system("pause");}
		}
		if(x==3)
		{  system("color 0D");
		   if(g==0)
		   {printf("����������ϵ��\n");
		   system("pause");}
		   else
		   {
			printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
			for(c=0;c<g;c++)
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", hmd[c].name, hmd[c].sex, hmd[c].age, hmd[c].work, hmd[c].workphone,hmd[c].phone, hmd[c].sort, hmd[c].mail);
		system("pause");}
		}
		if(x==4)
	{				//д��
    FILE *p = fopen("456.txt", "w");
    	for(c=0;c<g;c++)
    {
       	fprintf(p,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", hmd[c].name, hmd[c].sex, hmd[c].age, hmd[c].work, hmd[c].workphone,hmd[c].phone, hmd[c].sort, hmd[c].mail);
    }
    fclose(p);
	printf("����ɹ�!");
	system("pause");
    return 0;
}
		if(x==5)
	{			//��ȡ
	int c=0;
	FILE *fp;
	if((fp=fopen("������.txt","r"))==NULL)		
	{
		printf("Can not open file\n");
		exit(1);
	}
	while(!feof(fp))                    
	{    
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", hmd[c].name, hmd[c].sex, hmd[c].age, hmd[c].work, hmd[c].workphone,hmd[c].phone, hmd[c].sort, hmd[c].mail);
		c++;
	}         
    g=c;
printf("����:\t�Ա�:\t����:\t������λ:\t\t�����绰:\t�ֻ�:\t\t���:\t����:\t\n");
	for(c=0;c<g;c++)
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", hmd[c].name, hmd[c].sex, hmd[c].age, hmd[c].work, hmd[c].workphone,hmd[c].phone, hmd[c].sort, hmd[c].mail);
	fclose(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", hmd[c].name, hmd[c].sex, hmd[c].age, hmd[c].work, hmd[c].workphone,hmd[c].phone, hmd[c].sort, hmd[c].mail);				 
    system("pause");
	return;
}
		if(x==0)
			return 0; 
}
main(){
    int s,a,co;
    struct num person[200];  //�ṹ������
struct num hmd[200];
    for(co=0;co<10;co++)
    {
        system("color 0a");
        system("type ascii2.txt");
        system("ping 127.0.0.1 -n 1 >nul");
        system("cls");
        system("color a0");
        system("type ascii2.txt");
        system("ping 127.0.0.1 -n 1 >nul");
        system("cls");
    }
    system("color 0E");
    login();
    while(1) {
        menu();
        printf("����������ѡ��:");
        scanf("%d", &s);
        switch (s) {
            case 1:
                system("color 0A");
                input(person);//����
                break;
            case 2:
				 system("color 0C");
				getchar();
                xiugai(person);  //�޸�
                system("pause");
                break;
            case 3:
				 system("color 0D");
                shanchu(person);
                system("pause");
                break;
            case 4: system("color 0E");
				printf("��ѡ����Ҫѡ��ķ�ʽ:1-->��������ʾ\t2-->�������ʾ\t3-->�˳�\n");
                scanf("%d",&s);
                if(s==1)
                { system("color 0F");
					xianshi(person);
                    system("pause");
                }
                else if(s==2)
                { system("color 0B");
					leibie(person);
                    system("pause");}

                else if(s==3)
                break;
                else
                {printf("����������!\n");
                    system("pause");}
                break;
            case 5:
				 system("color 0C");
                printf("��ѡ���ѯ��ʽ:1-->������ѯ\t2-->�绰�����ѯ3-->�˳�\n");
                scanf("%d", &a);
                if (a == 1)
				{system("color 0D");
					 getchar();
                    chaxun1(person);
                    system("pause");}//������ѯ
                else if (a == 2)
                { system("color 0E");
					getchar();
                    chaxun2(person);
                    system("pause");}//�绰�Ų�ѯ
                else if(a==3)
                    break;
                else
                {printf("����������!\n");
                system("pause");}
                break;
            case 6: system("color 0D");
				count(person);
                system("pause");//ͳ��
                break;
            case 7:system("color 0C");
				file_read(person);      //��ȡ
                system("pause");
                break;
            case 8:system("color 0D");
				file_write(person);// ����
                system("pause");
                break;
			case 9:system("color 0B");
				henmingdan(person,hmd);
				break;
            case 0:
                return 0;
            default:
             printf("����������!\n");
                system("pause");
                break;

        }
    }
}

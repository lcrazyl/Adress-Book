#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int i=0,g=0;
struct num{
    char name[100]; //姓名
    char sex[100];//性别
    char age[50];//年龄
    char work[200];//工作单位
    char workphone[200];//工作电话
    char phone[200];//手机
    char sort[100];//类别
    char mail[200];//邮箱
};
void login()    //登录
{
    int j;
    system("type ascii.txt");
    for(j=0;j<3;j++)
    {
        int i=0;
        char c_usr[10]="student",c_pwd[10]="pass1234";    //正确用户名密码
        char usr[10],pwd[10];    //用户输入
        printf("请输入用户名：\n");
        gets(usr);
        printf("请输入密码：\n");
        while (i<10)
        {

            pwd[i] = getch();
            if(pwd[i]=='\r')
                break;
            if(pwd[i]!='\b')
            {
                i++;
                printf("*");//显示*号
            }
            else
            {
                i--;
                printf("\b \b");	//退格
            }
        }
        pwd[i]='\0';
        if(strcmp(c_usr, usr)==0)
            if(strcmp(c_pwd, pwd)==0)
            {
                printf("登录成功\n");
                system("pause");
                system("cls");
                break;
            }
            else
                printf("密码错误\n");
        else
        {
            printf("用户名错误\n");
        }

    }
    if(j>2)
    {
        printf("输入错误次数达到上限\n");
        exit(0);
    }
}
void input(struct num  person[]) {    //输入
    int j,x;   //x为控制手机号位数，j为循环变量
    char o[5];  //输入是否添加联系人的变量
    while (1) {
        printf("是否要添加联系人:");
        scanf("%s", &o);
        if (strcmp(o,"是")==0) {
            printf("姓名:");
            scanf("%s", person[i].name);
            for (j = 0; j <i; j++)      //判断联系人是否重复
                if (strcmp(person[i].name,person[j].name)==0)
                {printf("联系人已存在!\n");
                    system("pause");
                    return;}
            printf("性别:");
            scanf("%s", person[i].sex);
            if(strcmp(person[i].sex,"男")==0||strcmp(person[i].sex,"女")==0) //判断性别正确
                printf("年龄:");
            else
            {printf("请输入正确的性别!\n");
                system("pause");
                return 0;}
            scanf("%s", person[i].age);
            printf("工作单位:");
            scanf("%s", person[i].work);
            printf("工作电话:");
            scanf("%s", person[i].workphone);
            printf("手机:");
            scanf("%s", person[i].phone);
            x=strlen(person[i].phone);
            if(x<11||x>11)    //判断位数
            {printf("请输入正确的手机号码！\n");
                system("pause");
                return 0;}
            printf("类别:");
            scanf("%s", person[i].sort);
            printf("邮箱:");
            scanf("%s", person[i].mail);
            i++;
        }
        else
        {printf("请继续操作!\n");
            system("pause");
            break;
            }
    }
}
void chaxun1(struct num person[]) {     //用姓名查询
    int j;
    char name[20];   //用于输入查询的姓名
    printf("请输入您要查询该联系人的姓名:");
    gets(name);
    for (j = 0; j <i; j++)
        if (strcmp(name,person[j].name)==0)
            break;
    if(j>=i)
        printf("无该联系人\n");
    else
    {printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
               person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}
}
void chaxun2(struct num person[]) {    //用电话号码查询
    int j;
    char phone[20];
    printf("请输入您要查询该联系人的手机号码:");
    gets(phone);
    for (j = 0; j <i; j++)
        if (strcmp(phone,person[j].phone)==0)
            break;
    if(j>=i)
        printf("无该联系人\n");
    else
    {       printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
               person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}
}
void count(struct num person[])     //统计
{
    int boy=0,girl=0,sum=0,j,nel=0;
    for(j=0;j<i;j++)
    {
        if(strcmp(person[j].sex,"男")==0)
            boy++;
        else if(strcmp(person[j].sex,"女")==0)
            girl++;
    }
    sum=boy+girl;
    printf("-------------------------------\n");
    printf("|      男生人数共%d人          |\n",boy);
    printf("|-----------------------------|\n");
    printf("|      女生人数共%d人          |\n",girl);
    printf("|-----------------------------|\n");
    printf("|       总人数共%d人	      |\n",sum);
    printf("-------------------------------\n");
}

void xiugai(struct num person[]){     //修改信息
    int j,x;    //j为循环变量，x为输入将要修改的部分
    char name[200];
    printf("请输入您要修改信息的人名:");
    gets(name);
    for(j=0;j<i;j++)
        if(strcmp(person[j].name,name)==0)
		break;
		if(j<i)
		{printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
		person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}

    if(strcmp(person[j].name,name)!=0)
        printf("无该联系人!\n");
    else
    {
        printf("请选择您要修改的部分:\n");
        printf("------------------------\n");
        printf("|       1-->姓名       |\n");
        printf("|       2-->性别       |\n");
        printf("|       3-->年龄       |\n");
        printf("|       4-->工作地点   |\n");
        printf("|       5-->工作电话   |\n");
        printf("|       6-->手机       |\n");
        printf("|       7-->类别       |\n");
        printf("|       8-->邮箱       |\n");
        printf("-------------------------\n");
        scanf("%d",&x);
        switch(x){
            case 1:printf("请输入您要修改的姓名:\n");
                scanf("%s",person[j].name);
                printf("修改成功!\n");
                break;
            case 2:printf("请输入您要修改的性别:\n");
                scanf("%s",person[j].sex);
                printf("修改成功!\n");
                break;
            case 3:printf("请输入您要修改的年龄:\n");
                scanf("%s",person[j].age);
                printf("修改成功!\n");
                break;
            case 4:printf("请输入您要修改的工作地点:\n");
                scanf("%s",person[j].work);
                printf("修改成功!\n");
                break;
            case 5:printf("请输入您要修改的工作电话:\n");
                scanf("%s",person[j].workphone);
                break;
            case 6:printf("请输入您要修改的手机号码:\n");
                scanf("%s",person[j].phone);
                printf("修改成功!\n");
                break;
            case 7:printf("请输入您要修改的类别:\n");
                scanf("%s",person[j].sort);
                break;
            case 8:printf("请输入您要修改的邮箱:\n");
                scanf("%s",person[j].mail);
                printf("修改成功!\n");
                break;
            default:printf("输入错误，修改失败\n");}
		printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
		person[j].workphone,person[j].phone, person[j].sort, person[j].mail);

    }
}
void xianshi(struct num person[]){       //根据姓名顺序显示
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
    printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
    for(j=0;j<i;j++)
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work,
               person[j].workphone,person[j].phone, person[j].sort, person[j].mail);}


void shanchu(struct num person[])
{
    char f_name[50];
    char jueze[100];
    int j,k;
    printf("请输入您想删除联系人的姓名：");
    scanf("%s",f_name);
    for(j=0;j<i;j++)
    {
        if(strcmp(person[j].name,f_name)==0)
        {
            printf("请您确认是不是该联系人：\n");
            printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
            printf("是否继续删除？\n");
            scanf("%s",&jueze);
            if(strcmp(jueze,"是")==0)
            {
                for(k=j;k<i-1;k++)
                    person[k]=person[k+1];
                i--;
                printf("删除成功！\n");
                }

            else
                printf("请继续操作!\n");
                break;
        }


    }
    if(j>=i-1)
    printf("无该联系人!\n");
}
void leibie(struct num person[])
{
    int j,k=0,l=0,z=0,x=0,v=0,s=0,nn=0;
    printf("=====================================================================================\n");
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"家人")==0)
        {	nn++;
            if(k==0&&strcmp(person[j].sort,"家人")==0)
            {
                k++;
                printf("家人:\n");
                printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");	}
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
        }
    }
    printf("家人共有%d位联系人\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    printf("\n");
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"朋友")==0)
        {
            nn++;
            if(l==0&&strcmp(person[j].sort,"朋友")==0)
            {
                l++;
                printf("朋友:\n");
                printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
            }
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
        }
    }
    printf("朋友共有%d位联系人\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"老师")==0)
        {
            nn++;
            if(z==0&&strcmp(person[j].sort,"老师")==0)
            {	z++;
                printf("老师：\n");
                printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
            }
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);

        }
    }
    printf("老师共有%d位联系人\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    for(j=0;j<=i;j++)
    {
        if(strcmp(person[j].sort,"同事")==0)
        {
            nn++;
            if(x==0&&strcmp(person[j].sort,"同事")==0)
            {
                x++;
                printf("同事：\n");
                printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
            }
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);

        }
    }
    printf("同事共有%d位联系人\n",nn);
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n");
    nn=0;
    for(j=0;j<i;j++)
    {
        if(strcmp(person[j].sort,"同事")==0)
            v++;
        else if(strcmp(person[j].sort,"老师")==0)
            v++;
        else if(strcmp(person[j].sort,"家人")==0)
            v++;
        else if(strcmp(person[j].sort,"朋友")==0)
            v++;
            //if(strcmp(person[j].sort,"同事")==0&&strcmp(person[j].sort,"老师")==0&&strcmp(person[j].sort,"家人")==0&&strcmp(person[j].sort,"朋友")==0)
        else if(v==j&&s==0){
            s++;
            v++;
            nn++;
            printf("其他：\n");
            printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);}
        else if(v==j){
            nn++;
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", person[j].name, person[j].sex, person[j].age, person[j].work, person[j].workphone,
                   person[j].phone, person[j].sort, person[j].mail);
        }
    }
    printf("其他共有%d位联系人\n",nn);
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
    printf("\t\t\t\t\t\t\t\t\t |      1->请添加新的联系人          |\n");
    printf("\t\t\t\t\t\t\t\t\t |      2->修改已有联系人的信息      |\n");
    printf("\t\t\t\t\t\t\t\t\t |      3->删除某个联系人            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      4->显示所有联系人信息        |\n");
    printf("\t\t\t\t\t\t\t\t\t |      5->查询联系人信息            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      6->统计男女联系人和总人数    |\n");
    printf("\t\t\t\t\t\t\t\t\t |      7->读取联系人信息            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      8->保存联系人信息            |\n");
    printf("\t\t\t\t\t\t\t\t\t |      9->黑名单                    |\n");
    printf("\t\t\t\t\t\t\t\t\t |      0->退出                      |\n");
    printf("\t\t\t\t\t\t\t\t\t ------------------------------------- \n");}

void file_write(struct num person[])  //写入
{
    int j;
    FILE *data;
    data=fopen("data.csv","w");
    if(data==NULL)
    {
        printf("文件无法打开\n");
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
    printf("保存成功!\n");
}

void file_read(struct num person[])   //读取
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
    printf("读取成功\n");
    fclose(data);
}
void henmingdan(struct num person[],struct num hmd[]){			//黑名单
		int x,j,c;
		char name[50];
		printf("请输入您的选择:\n");
        printf("------------------------------\n");
        printf("|       1-->加入黑名单       |\n");
        printf("|       2-->移除黑名单       |\n");
        printf("|       3-->查看黑名单联系人 |\n");
        printf("|       4-->保存             |\n");
        printf("|       5-->读取             |\n");
        printf("|       0-->退出             |\n");
        printf("------------------------------\n");
		scanf("%d",&x);
		if(x==1)
		{system("color 0C");
		printf("请输入一个名字，把他拉入黑名单\n");
			getchar();
			gets(name);
		for(j=0;j<i;j++)
			if(strcmp(name,person[j].name)==0)
				break;
		if(j<i)
			{
			hmd[g]=person[j];	
			g++;
			printf("加入黑名单成功\n");
			for(j=i;j<i-1;j++)
				{
				person[j]=person[j+1];
				}
			i--;	
			}
		else
			printf("没有该联系人\n");
		system("pause");
		}
		if(x==2)
		{system("color 0D");
			printf("请输入一个名字，把他取消黑名单\n");
			getchar();
			gets(name);
			for(c=0;c<g;c++)
			if(strcmp(name,hmd[c].name)==0)
				break;
			if(c<g)
			{
					person[i]=person[c];
					i++;
					printf("取消黑名单成功\n");
					system("pause");
				for(j=c;j<g-1;j++)
					hmd[j]=hmd[j+1];
					g--;
			}
			else
			{	printf("黑名单里没有该联系人\n");
			system("pause");}
		}
		if(x==3)
		{  system("color 0D");
		   if(g==0)
		   {printf("黑名单无联系人\n");
		   system("pause");}
		   else
		   {
			printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
			for(c=0;c<g;c++)
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", hmd[c].name, hmd[c].sex, hmd[c].age, hmd[c].work, hmd[c].workphone,hmd[c].phone, hmd[c].sort, hmd[c].mail);
		system("pause");}
		}
		if(x==4)
	{				//写入
    FILE *p = fopen("456.txt", "w");
    	for(c=0;c<g;c++)
    {
       	fprintf(p,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", hmd[c].name, hmd[c].sex, hmd[c].age, hmd[c].work, hmd[c].workphone,hmd[c].phone, hmd[c].sort, hmd[c].mail);
    }
    fclose(p);
	printf("保存成功!");
	system("pause");
    return 0;
}
		if(x==5)
	{			//读取
	int c=0;
	FILE *fp;
	if((fp=fopen("黑名单.txt","r"))==NULL)		
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
printf("姓名:\t性别:\t年龄:\t工作单位:\t\t工作电话:\t手机:\t\t类别:\t邮箱:\t\n");
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
    struct num person[200];  //结构体数组
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
        printf("请输入您的选择:");
        scanf("%d", &s);
        switch (s) {
            case 1:
                system("color 0A");
                input(person);//输入
                break;
            case 2:
				 system("color 0C");
				getchar();
                xiugai(person);  //修改
                system("pause");
                break;
            case 3:
				 system("color 0D");
                shanchu(person);
                system("pause");
                break;
            case 4: system("color 0E");
				printf("请选择您要选择的方式:1-->按姓名显示\t2-->按类别显示\t3-->退出\n");
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
                {printf("您输入有误!\n");
                    system("pause");}
                break;
            case 5:
				 system("color 0C");
                printf("请选择查询方式:1-->姓名查询\t2-->电话号码查询3-->退出\n");
                scanf("%d", &a);
                if (a == 1)
				{system("color 0D");
					 getchar();
                    chaxun1(person);
                    system("pause");}//姓名查询
                else if (a == 2)
                { system("color 0E");
					getchar();
                    chaxun2(person);
                    system("pause");}//电话号查询
                else if(a==3)
                    break;
                else
                {printf("您输入有误!\n");
                system("pause");}
                break;
            case 6: system("color 0D");
				count(person);
                system("pause");//统计
                break;
            case 7:system("color 0C");
				file_read(person);      //读取
                system("pause");
                break;
            case 8:system("color 0D");
				file_write(person);// 保存
                system("pause");
                break;
			case 9:system("color 0B");
				henmingdan(person,hmd);
				break;
            case 0:
                return 0;
            default:
             printf("您输入有误!\n");
                system("pause");
                break;

        }
    }
}

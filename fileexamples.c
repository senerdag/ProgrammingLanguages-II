#include <stdio.h>
#include <stdlib.h>

struct student
{
    int no;
    char isim[10];
    int age;
    char ill[10];
};

int main()
{
    struct student bos = {0, "", 0, ""};
    struct student dolu = {0, "", 0, ""};

    FILE *fp, *dd;

    int x, search;
    while (1)
    {
        printf("\nSecim yapin");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            if ((fp = fopen("aaa.dat", "r+")) == NULL)
            {
                printf("bsyler yolunda gitmedi.");
            }

            else
            {
                printf("no girin: ");
                scanf("%d", &bos.no);
               
                fseek(fp,(bos.no-1)*sizeof(struct student),SEEK_SET);


                printf("Isim girin: ");
                scanf("%s", bos.isim);
                printf("Yas girin: ");
                scanf("%d", &bos.age);
                printf("Hastalik girin: ");
                scanf("%s", bos.ill);

                fwrite(&bos, sizeof(struct student), 1, fp);
            }
            fclose(fp);
            break;
        case 2:

            if ((dd = fopen("aaa.dat", "r")) == NULL)
            {
                printf("bsyler yolunda gitmedi.");
            }

            else
            {

                while (!feof(dd))
                {
                    fread(&bos, sizeof(struct student), 1, dd);
                    printf("\n %d %s %d %s", bos.no, bos.isim, bos.age, bos.ill);
                }
            }
            fclose(dd);
            break;
        case 3:
            if ((dd = fopen("aaa.dat", "r")) == NULL)
            {
                printf("bsyler yolunda gitmedi.");
            }

            else
            {

                printf("hasta no gir: ");
                scanf("%d", &search);
                while (!feof(dd))
                {
                    fread(&bos, sizeof(struct student), 1, dd);
                    if (search == bos.no)
                    {
                        printf("\n %d %s %d %s", bos.no, bos.isim, bos.age, bos.ill);
                    }
                }
            }
            fclose(dd);

            break;
        case 4:

            

            if ((dd = fopen("aaa.dat", "r+")) == NULL)
            {
                printf("bsyler yolunda gitmedi.");
            }

            else
            {

                printf("hasta no gir: ");
                scanf("%d", &search);
                while (!feof(dd))
                {
                    fread(&bos, sizeof(struct student), 1, dd);
                    if (search == bos.no)
                    {
                        printf("\n %d %s %d %s", bos.no, bos.isim, bos.age, bos.ill);
                        fseek(dd,-sizeof(struct student),SEEK_CUR);
                        fwrite(&dolu, sizeof(struct student),1,dd);
                        break;
                    }
                }
            }
            fclose(dd);

            break;
        default:
            break;
        }
    }

    return 0;
}
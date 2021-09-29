#include <stdio.h>
#include <math.h>

main(void)
{
    int i,j,k,l,b,a,ranking[200][200],iterasi,loop,newmax,newmin,cl,iterasicl;
    float I[200][200],c[200][20],jarak[200],rank[200],jumlah[200],mean1[200][200],mean2[200][200],mean3[200][200], mean[200][200],kelas[200],kelastesting[200];
    float varian[200];
    cl=154;

    freopen("task1.txt","r",stdin);//if You want to notepad , with name input.txt
    for( int i = 1 ; i <=155; i++ )
    {
        for(j=1; j<=19; j++)
        {
            scanf("%f", &I[i][j]);
        }
        scanf("%f",&kelas[i]);
    }
/*
    for(i=1; i<=155; i++)
    {
        if(kelas[i]==0)
        {
            kelas[i]=1;
        }
        else if(kelas[i]==1)
        {
            kelas[i]=2;
        }
    }
*/


    //Data Baru yang sudah diNormalisasi Min-Max(0-1)
    //Data Learning
    newmax=1;
    newmin=0;
    for(i=1; i<=155; i++)
    {
        I[i][1]=((I[i][1]-7)*(newmax-newmin))/((78-7)+newmin);
        I[i][14]=((I[i][14]-1)*(newmax-newmin))/((8-1)+newmin);
        I[i][15]=((I[i][15]-26)*(newmax-newmin))/((295-26)+newmin);
        I[i][16]=((I[i][16]-14)*(newmax-newmin))/((648-14)+newmin);
        I[i][17]=((I[i][17]-3)*(newmax-newmin))/((5-3)+newmin);
        I[i][18]=((I[i][18]-0)*(newmax-newmin))/((100-0)+newmin);
        //printf("%d = %f %f %f %f %f %f\n",i,Age[i],Bilir[i],Alk[i],Sgot[i],Albumin[i],Protime[i]);
    }

    for(i=1; i<=cl; i++)
    {
        for(j=1; j<=19; j++)
        {
            c[i][j]=rand()%100/99.1938129;
            //printf("c[%d][%d]= %f\n",i,j,c[i][j]);
        }
    }


    for(iterasicl=0; iterasicl<=cl; iterasicl++)
    {
    loop=10;
    for(iterasi=1; iterasi<=loop; iterasi++)
    {

        for(i=1; i<=cl; i++)
        {
            jumlah[i]=0;
            for(j=1; j<=19; j++)
            {
                mean[i][j]=0;
            }
        }


        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        printf("\niterasi = %d\n\n",iterasi);
    for(i=1; i<=155; i++)
    {
        for(j=1; j<=cl; j++) //CLuster
        {
            jarak[j]=0;
            for(k=1; k<=19; k++) //Penjumlahan jarak
            {
                jarak[j]=jarak[j]+pow(I[i][k]-c[j][k],2);
            }
            jarak[j]=sqrt(jarak[j]);
            //printf("jarak[%d][%d]=%f\n",i,j,jarak[j]);
        }
         for(j=1; j<=cl; j++)
            {
                rank[j]=1;
                for(b=1; b<=cl; b++)
                    {
                        if(jarak[j]>jarak[b])
                        {
                            rank[j]++;
                        }
                    }
            }
            //printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=cl; j++)
        //printf("%f\t\t %f\n",jarak[j], rank[j]);

        for(j=1; j<=cl; j++)
        {
            for(k=1; k<=cl; k++)
            {
                if(rank[j]==1 && j==k)
                {
                    jumlah[j]=jumlah[j]+1;
                    ranking[i][j]=j;
                }
                else if(rank[j]!=1)
                {
                    ranking[i][j]=0;
                }
            }
        }

    }

    //printf("\n\n");
    for(i=1; i<=cl; i++)
    {
        //printf("jumlah[%d] = %f\n",i,jumlah[i]);
    }

    for(i=1; i<=155; i++)
    {
        //printf("i= %d   ",i);
        for(j=1; j<=cl; j++)
        {
            for(k=1; k<=cl; k++)
            {
                if(ranking[i][j]==k)
                {
                    kelastesting[i]=ranking[i][j];
                    //printf("class[%d] = %f\n",i,kelastesting[i]);
                    mean[ranking[i][j]][1]=mean[ranking[i][j]][1]+I[i][1];
                    mean[ranking[i][j]][2]=mean[ranking[i][j]][2]+I[i][2];
                    mean[ranking[i][j]][3]=mean[ranking[i][j]][3]+I[i][3];
                    mean[ranking[i][j]][4]=mean[ranking[i][j]][4]+I[i][4];
                    mean[ranking[i][j]][5]=mean[ranking[i][j]][5]+I[i][5];
                    mean[ranking[i][j]][6]=mean[ranking[i][j]][6]+I[i][6];
                    mean[ranking[i][j]][7]=mean[ranking[i][j]][7]+I[i][7];
                    mean[ranking[i][j]][8]=mean[ranking[i][j]][8]+I[i][8];
                    mean[ranking[i][j]][9]=mean[ranking[i][j]][9]+I[i][9];
                    mean[ranking[i][j]][10]=mean[ranking[i][j]][10]+I[i][10];
                    mean[ranking[i][j]][11]=mean[ranking[i][j]][11]+I[i][11];
                    mean[ranking[i][j]][12]=mean[ranking[i][j]][12]+I[i][12];
                    mean[ranking[i][j]][13]=mean[ranking[i][j]][13]+I[i][13];
                    mean[ranking[i][j]][14]=mean[ranking[i][j]][14]+I[i][14];
                    mean[ranking[i][j]][15]=mean[ranking[i][j]][15]+I[i][15];
                    mean[ranking[i][j]][16]=mean[ranking[i][j]][16]+I[i][16];
                    mean[ranking[i][j]][17]=mean[ranking[i][j]][17]+I[i][17];
                    mean[ranking[i][j]][18]=mean[ranking[i][j]][18]+I[i][18];
                    mean[ranking[i][j]][19]=mean[ranking[i][j]][19]+I[i][19];
                }
            }
        }
    }

    //printf("\n\n");
    for(i=1; i<=cl; i++)
    {
        for(j=1; j<=19; j++)
        {
            //printf("mean[%d][%d] = %f\n",i,j,mean[i][j]);
        }
    }

    //printf("\n\n");
    for(i=1; i<=cl; i++)
    {
        for(k=1; k<=cl; k++)
        {
            if(i==k)
            {
                for(j=1; j<=19; j++)
                {
                    if(jumlah[i]==0)
                    {
                        c[i][j]=0;
                    }
                    else if(jumlah[i]!=0)
                    {
                        c[i][j]=mean[i][j]/jumlah[i];
                    }
                    //printf("c[%d][%d] = %f\n",i,j,c[i][j]);
                }
            }
        }

    }
    }

    //MENGHITUNG PERFORMANCE DENGAN "VARIAN"
    //Menghitung nC /Jumlah data pada Cluster C
    int nC[200];
    nC[1]=0;
    nC[2]=0;
    for(i=1; i<=155; i++)
    {
        for(j=1; j<=cl; j++)
        {
            if(kelastesting[i]==j)
            {
                nC[j]=nC[j]+1;
            }
        }
    }
    for(i=1; i<=cl; i++)
    {
        printf("nC[%d] = %d\n",i,nC[i]);
    }
    //Menghitung dibar atau xi bar atau rata2
    float dibar[200];
    for(j=1; j<=19; j++)
    {
        for(i=1; i<=155; i++)
        {
            for(k=1; k<=cl; k++)
            {
                if(kelastesting[i]==k)
                {
                    dibar[k]=dibar[k]+I[i][j];
                }
            }
        }
    }
    for(i=1; i<=cl; i++)
    {
        if(nC[i]==0)
        {
            dibar[i]=0;
        }
        else if(nC[i]!=0)
        {
            dibar[i]=dibar[i]/nC[i];
        }
        //printf("dibar[%d] = %f\n",i,dibar[i]);
    }
    //Menghitung didibar
    float didibar[200][25];
    for(j=1; j<=19; j++)
    {
        //didibar[1][j]=0;
        //didibar[2][j]=0;
        for(i=1; i<=155; i++)
        {
            for(k=1; k<=cl; k++)
            {
                if(kelastesting[i]==k)
                {
                    didibar[k][j]=didibar[k][j]+ pow((I[i][j]-dibar[k]),2);
                }
            }
        }
    }
    //Menghitung Cluster Variance (Vc)
    float Vc[200][19];
    for(i=1; i<=19; i++)
    {
        for(j=1; j<=cl; j++)
        {
            if((nC[j]-1)==0)
            {
                Vc[j][i]=0;
            }
            else if((nC[j]-1)!=0)
            {
                Vc[j][i]=didibar[j][i]/(nC[j]-1);
            }
            //printf("Vc[%d][%d]= %f\n",j,i,Vc[j][i]);
        }
    }

    //MENGHITUNG Vw / VARIANCE WITHIN CLUSTER
    //Menghitung sigma (n1-1)v1
    float nivi[200][20];
    for(i=1; i<=19; i++)
    {
        for(j=1; j<=cl; j++)
        {
            nivi[j][i]=(nC[j]-1)*Vc[j][i];
            //printf("nivi[%d][%d] = %f\n",j,i,nivi[j][i]);
        }
    }
    //Menghitung nilai Vw
    float Vw[200];
    for(i=1; i<=19; i++)
    {
        Vw[i]=0;
        for(j=1; j<=cl; j++)
        {
            Vw[i]=Vw[i]+nivi[j][i];
        }
        //printf("Vw[%d] = %f\n",i,Vw[i]);
        Vw[i]= Vw[i]/(155-cl);
        //printf("Vw[%d] = %f\n",i,Vw[i]);
    }

    //MENGHITUNG VB / VARIANCE BETWEEN CLUSTERS
    //X bar data semua
    float xbardata[200];
    for(i=1; i<=19; i++)
    {
        xbardata[i]=0;
        for(j=1; j<=155; j++)
        {
            xbardata[i]=xbardata[i]+I[j][i];
        }
        xbardata[i]=xbardata[i]/155;
    }
    //Mencari n1*(xbar klaster - xbardata)^2
    float nxbar[200][20];
    for(i=1; i<=19; i++)
    {
        for(j=1; j<=cl; j++) //cluster
        {
            nxbar[j][i]=nC[j]*pow((dibar[j]-xbardata[i]),2);
            //printf("nxbar[%d][%d] = %f\n",j,i,nxbar[j][i]);
        }
    }
    //Menghitung Vb
    float Vb[200];
    for(i=1; i<=19; i++)
    {
        Vb[i]=0;
        for(j=1; j<=cl; j++) //Cluster
        {
            Vb[i]=Vb[i]+nxbar[j][i];
        }
        Vb[i]=Vb[i]/(cl-1);
        //printf("Vb[%d] = %f\n",i,Vb[i]);
    }

    //MENGHITUNG V
    //Menghitung V, yang belum dirata2 oleh semua attribute
    float V[20];
    for(i=1; i<=19; i++)
    {
        V[i]=Vw[i]/Vb[i];
        //printf("V[%d] = %f\n",i,V[i]);
    }
    //Menghitung V yang fix, sudah dihitung rata2 perattributenya
    float ve;
    ve=0;
    for(i=1; i<=19; i++)
    {
        ve=ve+V[i];
    }
    //printf("V=%f\n",ve);


    varian[iterasicl]=ve;

    }

    for(i=0; i<=cl; i++)
    {
        //printf("varian[%d] = %f\n",i+1,varian[i]);
    }

    //VALLEY-TRACING
    float delta[200];
    varian[0]=0;
    for(i=1; i<=cl; i++)
    {
        if((varian[i-1]>=varian[i])&&varian[i]<varian[i+1])
        {
            delta[i] = (varian[i+1]-varian[i])+(varian[i-1]-varian[i]);
            printf("delta[%d]= %f\n",i,delta[i]);
        }
        else
        {
            delta[i]=0;
            printf("delta[%d]= %f\n",i,delta[i]);
        }
    }
    //RANKING NILAI DELTA=MAX
    int peringkat[200];
    for(j=1; j<=cl; j++)
            {
                peringkat[j]=1;
                for(b=1; b<=cl; b++)
                    {
                        if(delta[j]>delta[b])
                        {
                            peringkat[j]++;
                        }
                    }
            }
            printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=cl; j++)
        printf("%f\t\t %d\n",delta[j], peringkat[j]);
    //Kesimpulan Ideal Cluster
    for(i=1; i<=cl; i++)
    {
        if(peringkat[i]==cl) //Peringkat dengan delta max
        {
            printf ("IDEAL CLUSTER = %d\n",i);
        }
    }

    //Accuracy
    float akurasi;
    float p,q;
    for(i=1; i<=cl; i++)
    {
        if(peringkat[i]==cl)
        {
            p=delta[i];
        }
        else if(peringkat[i]==(cl-1))
        {
            q=delta[i];
        }
    }
    akurasi=p/q;
    printf("akurasi = %f\n",akurasi);



    /*
    //MENGHITUNG PERFORMANCE DENGAN METODE "ERROR RATIO"
    int error;
    error=0;
    for(i=1; i<=155; i++)
    {
        if(kelas[i]==kelastesting[i])
        {
            error=error+0;
        }
        else if(kelas[i]!=kelastesting[i])
        {
            error=error+1;
        }
    }

    printf("error = %d\n",error);
    float totalerror = error*100/155;
    printf("totalerror = %f\n",totalerror);
    */


    }


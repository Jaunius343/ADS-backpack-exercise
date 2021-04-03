#include <stdio.h>
#include <stdlib.h>

typedef struct product {
    int weight;
    int price;
}Product;

void read_from_file(FILE *read, int *quan, int *max_weight, Product **products);

int main()
{
    FILE *read;
    read = fopen("duom.txt", "r");
    int quantity;
    int max_allowed_weight;
    if(read != NULL){
        Product *products;
        read_from_file(read, &quantity, &max_allowed_weight, &products);
        fclose(read);

//        printf("%d\n",products);
//        printf("%d %d\n", quantity, max_allowed_weight);
//        for(int i = 0; i < quantity; ++i){
//            printf("%d %d %d\n", i + 1, products[i].weight, products[i].price);
//        }

        int **lentele = (int **)calloc(quantity+1, sizeof(int *));
        for(int i = 0; i < quantity+1; ++i){
            lentele[i] = (int *)calloc(max_allowed_weight+1, sizeof(int));
        }
//        for(int i = 0; i < quantity+1; ++i){
//            for(int j = 0; j < max_allowed_weight+1; ++j){
//                printf("%d ", lentele[i][j]);
//            }
//            printf("\n");
//        }

        for(int r = 1; r < max_allowed_weight+1; ++r){
            for (int k = 1; k < quantity+1; ++k){
                if(products[k-1].weight <= r){
//                    printf("%d ",lentele[k - 1][r]);
//                    printf("%d ",products[k].price + lentele[k - 1][r - products[k].weight]);
                    lentele[k][r] = fmax(lentele[k - 1][r], products[k-1].price + lentele[k - 1][r - products[k-1].weight]);
                } else {
                    lentele[k][r] = lentele[k - 1][r];
                }
            }
        }

//        for(int i = 0; i < quantity+1; ++i){                              //i - daiktu kiekis
//            for (int j = 0; j < max_allowed_weight+1; ++j){               //j - daiktu svoris
//                printf("%d ", lentele[i][j]);
//            }
//            printf("\n");
//        }

        int *selected = (int *)malloc(quantity * sizeof(int));
        for(int i = 0; i < quantity; ++i){
            selected[i] = 0;
        }
//        printf("\nselected:\n");
//        for(int i = 0; i < quantity; ++i){
//            printf("%d\n", selected[i]);
//        }

        int k = quantity;
        int r = max_allowed_weight;
        while(k > 0 && r > 0){
//            printf("%d %d\n", k, r);
//            printf("%d ", lentele[k][r]);
//            printf("%d \n", lentele[k - 1][r]);
            if(lentele[k][r] > lentele[k - 1][r]){
//                printf("ok");
                selected[k-1] = 1;
                r = r - products[k-1].weight;
            }
            k = k - 1;
        }
//        printf("ok");

//        printf("\nselected:\n");
//        for(int i = 0; i < quantity; ++i){
//            printf("%d\n", selected[i]);
//        }

        printf("\nSelected\n");
        for(int i = 0; i < quantity; ++i){
            if (selected[i] == 1){
                printf("%d %d\n", products[i].weight, products[i].price);
            }
        }

//        float total_price = 0;
//        for(int i = 0; i < count; ++i){
//            printf("%d %0.1f %0.1f\n", i+1, selected[i].weight, selected[i].price);
//            total_price +=  selected[i].price;
//        }
//        printf("max allowed weight: %0.1f\n", max_allowed_weight);
//        printf("selected weight: %0.1f\n", total_weight);
//        printf("total price: %0.1f\n", total_price);
//    printf("%d", quantity);
    }
    return 0;
}


void read_from_file(FILE *read, int *quan, int *max_weight, Product **products)
{
    int temp_int;
    fscanf(read, "%d", &temp_int);
    *quan = temp_int;
    //printf("%d", *q);

    int temp_float;
    fscanf(read, "%d", &temp_float);
    *max_weight = temp_float;

    Product *temp_product = malloc(temp_int * sizeof(Product));
    for(int i = 0; i < temp_int; ++i){
        fscanf(read, "%d", &temp_product[i].weight);
        fscanf(read, "%d", &temp_product[i].price);
    }

//    for(int i = 0; i < temp_int; ++i){
//            printf("%d %f %f\n", i + 1, temp_product[i].weight, temp_product[i].price);
//    }

    *products = temp_product;
//    printf("%d\n", temp_product);
}

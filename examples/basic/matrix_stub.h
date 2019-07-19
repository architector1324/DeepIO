#pragma once
#include <stdio.h>


void stub_map(const dcl_matf* A, float(*f)(float), dcl_matf* result){
    size_t size = result->h * result->w;

    for(size_t i = 0; i < size; i++)
        result->data[i] = f(A->data[i]);
}

void stub_add(const dcl_matf* A, const dcl_matf* B, dcl_matf* result){
    size_t size = result->h * result->w;

    for(size_t i = 0; i < size; i++)
        result->data[i] = A->data[i] + B->data[i];
}

void stub_sub(const dcl_matf* A, const dcl_matf* B, dcl_matf* result){
    size_t size = result->h * result->w;

    for(size_t i = 0; i < size; i++)
        result->data[i] = A->data[i] - B->data[i];
}

void stub_mul(const dcl_matf* A, const dcl_matf* B, dcl_matf* result, DCL_TRANSPOSE option){
    if(option == NONE){
        size_t h = A->h;
        size_t w = B->w;
        size_t A_w = A->w;

        for(size_t i = 0; i < h; i++){
            size_t A_offset = i * A_w;

            for(size_t j = 0; j < w; j++){
                float sum = 0;
                for(size_t k = 0; k < A_w; k++)
                    sum += A->data[A_offset + k] * B->data[k * w + j];

                result->data[i * w + j] = sum;
            }
        }
    }else if(option == FIRST){
        size_t h = A->w;
        size_t w = B->w;
        size_t A_w = A->h;

        for(size_t i = 0; i < h; i++){
            for(size_t j = 0; j < w; j++){
                float sum = 0;
                for(size_t k = 0; k < A_w; k++)
                    sum += A->data[k * h + i] * B->data[k * w + j];

                result->data[i * w + j] = sum;
            }
        }
    }else if(option == SECOND){
        
    }else{
        
    }
}

void stub_had(const dcl_matf* A, const dcl_matf* B, dcl_matf* result){
    size_t size = result->h * result->w;

    for(size_t i = 0; i < size; i++)
        result->data[i] = A->data[i] * B->data[i];
}

void stub_printf(const dcl_matf* A){
    size_t h = A->h;
    size_t w = A->w;

    for(size_t i = 0; i < h; i++){
        size_t offset = i * w;
        for(size_t j = 0; j < w; j++)
            printf("%f ", A->data[offset + j]);
        puts("");
    }
    puts("");
}

dcl_matf_operations stub_ops = {
    .map = stub_map,
    .add = stub_add,
    .sub = stub_sub,
    .mul = stub_mul,
    .had = stub_had
};
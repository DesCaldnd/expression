//
// Created by Des Caldnd on 11/14/2023.
//

#ifndef EXPRESSION_EXTERN_H
#define EXPRESSION_EXTERN_H

#if (__cplusplus)
#define EXTERN_START extern "C" {
#define EXTERN_END }
#else
#define EXTERN_START
#define EXTERN_END
#endif

#endif //EXPRESSION_EXTERN_H

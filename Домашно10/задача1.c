int main() {
    double a, b;
    printf("Enter two double values: ");
    scanf("%lf %lf", &a, &b);

    double *pA = &a, *pB = &b;
    printf("Address of pA: %p, Value: %lf\n", (void*)pA, *pA);
    printf("Address of pB: %p, Value: %lf\n", (void*)pB, *pB);
    
    return 0;
}


#define DEG_PIN_1_BEGIN clock_t start,end; start = clock();
#define DEG_PIN_1_END end = clock();ff(debug,"%.7f\n",double(end-start)/double(CLOCKS_PER_SEC));

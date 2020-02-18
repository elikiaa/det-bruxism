#pragma once
/**
 * Compute kernel between feature vector and support vector.
 * Kernel type: poly
 * Output of micromlgen of SVM Classifier
 */
double compute_kernel(double x[15], int nfeatures, ...) {
    va_list w;
    double kernel = 0.0;
    float  coeff  = 1/15;
    va_start(w, nfeatures);
    for (byte i = 0; i < 15; i++)
            kernel += x[i] *  va_arg(w, double) ;
        kernel = pow((coeff * kernel) + 0.0, 2); // auto uses 1 / n_features see: https://scikit-learn.org/stable/modules/generated/sklearn.svm.SVC.html#sklearn.svm.SVC.decision_function
    return kernel;
}
/**
 * Predict class for features vector
 */
byte predict(double *x) {
    double kernels[66] = { 0 };
    double decisions[1] = { 0 };
    byte votes[2] = { 0 };
        kernels[0] = compute_kernel(x, 15,  0.171447336  , 0.171447336  , 0.0  , 0.000922063  , 3.776770639  , 0.029738351  , 26.0  , 0.557184751  , 0.004353006  , 0.171773166  , 21.945259042  , 0.171447336  , 0.010575042  , 0.006344529  , 0.171131235 );
        kernels[1] = compute_kernel(x, 15,   0.303946725  , 0.303946725  , 0.257361926  , 0.25770958  , 12.036503527  , 0.094775618  , 36.0  , 0.669599218  , 0.005231244  , 0.306651567  , 38.905180841  , 0.303946725  , 0.040639537  , 0.006760762  , 0.301046431 );
        kernels[2] = compute_kernel(x, 15,  0.210624389  , 0.210624389  , 0.014319098  , 0.015598725  , 5.721389469  , 0.045050311  , 43.0  , 1.001955034  , 0.007827774  , 0.211419855  , 26.959921799  , 0.210624389  , 0.018322717  , 0.0114007  , 0.209879385 );
        kernels[3] = compute_kernel(x, 15,  0.158006476  , 0.158006476  , 0.0  , 0.000780762  , 3.198000247  , 0.025181104  , 23.0  , 0.400782014  , 0.003131109  , 0.158064471  , 20.224828935  , 0.158006476  , 0.004281408  , 0.004380186  , 0.157948495 );
        kernels[4] = compute_kernel(x, 15,  0.856396628  , 0.856396628  , 0.856396628  , 0.856396628  , 93.897254639  , 0.739348462  , 45.0  , 1.080156403  , 0.008438722  , 0.856488355  , 109.618768328  , 0.856396628  , 0.012534678  , 0.010946171  , 0.856305462 );
        kernels[5] = compute_kernel(x, 15,  0.924020956  , 0.924020956  , 0.924020956  , 0.924020956  , 109.321600261  , 0.860800002  , 35.0  , 0.635386119  , 0.004963954  , 0.924161783  , 118.274682307  , 0.924020956  , 0.016133065  , 0.00646203  , 0.923879915 );
        kernels[6] = compute_kernel(x, 15,  0.896681024  , 0.896681024  , 0.896681024  , 0.896681024  , 102.951017124  , 0.81063793  , 36.0  , 0.698924731  , 0.005460349  , 0.896830431  , 114.775171065  , 0.896681024  , 0.016369562  , 0.007347396  , 0.896531043 );
        kernels[7] = compute_kernel(x, 15,  0.200849218  , 0.200849218  , 0.0  , 0.001261938  , 5.168896419  , 0.040699972  , 37.0  , 0.782013685  , 0.006109482  , 0.200952739  , 25.708699902  , 0.200849218  , 0.006449411  , 0.008251764  , 0.200746359 );
        kernels[8] = compute_kernel(x, 15,  0.164956012  , 0.164956012  , 0.0  , 0.000851436  , 3.487480997  , 0.02746048  , 25.0  , 0.469208211  , 0.003665689  , 0.165063458  , 21.114369501  , 0.164956012  , 0.005954786  , 0.005347051  , 0.164853017 );
        kernels[9] = compute_kernel(x, 15,  0.169729044  , 0.169729044  , 0.0  , 0.000904199  , 3.703600187  , 0.029162206  , 33.0  , 0.684261975  , 0.005345797  , 0.170101077  , 21.725317693  , 0.169729044  , 0.011244017  , 0.008630582  , 0.169383395 );
        kernels[10] = compute_kernel(x, 15,  0.164421432  , 0.164421432  , 0.0  , 0.000845277  , 3.462254749  , 0.027261848  , 25.0  , 0.420332356  , 0.003283847  , 0.164465392  , 21.045943304  , 0.164421432  , 0.003802355  , 0.004711221  , 0.164377527 );
        kernels[11] = compute_kernel(x, 15,  0.823061767  , 0.823061767  , 0.823061767  , 0.823061767  , 96.327645961  , 0.758485401  , 48.0  , 2.2971652  , 0.017946603  , 0.867502008  , 105.351906158  , 0.823061767  , 0.274096811  , 0.031609785  , 0.785350718 );
        kernels[12] = compute_kernel(x, 15,  0.894924548  , 0.894924548  , 0.894924548  , 0.894924548  , 102.528573026  , 0.807311599  , 38.0  , 0.865102639  , 0.006758614  , 0.894988534  , 114.550342131  , 0.894924548  , 0.010701885  , 0.009190004  , 0.894860848 );
        kernels[13] = compute_kernel(x, 15,  0.228761913  , 0.228761913  , 0.076635814  , 0.077500652  , 9.036132778  , 0.071150652  , 48.0  , 1.402737048  , 0.010958883  , 0.265696796  , 29.281524927  , 0.228761913  , 0.135139832  , 0.019274187  , 0.206176549 );
        kernels[14] = compute_kernel(x, 15,  0.204247617  , 0.204247617  , 0.0  , 0.001306023  , 5.349469532  , 0.042121807  , 30.0  , 0.664711632  , 0.00519306  , 0.204432705  , 26.143695015  , 0.204247617  , 0.008697215  , 0.007685238  , 0.204066865 );
        kernels[15] = compute_kernel(x, 15,  0.852883675  , 0.852883675  , 0.852883675  , 0.852883675  , 93.140706087  , 0.733391387  , 47.0  , 0.977517107  , 0.007636852  , 0.853030929  , 109.169110459  , 0.852883675  , 0.015849367  , 0.010605792  , 0.852737467 );
        kernels[16] = compute_kernel(x, 15,  0.185919172  , 0.185919172  , 0.0  , 0.001094327  , 4.482365037  , 0.035294213  , 34.0  , 0.786901271  , 0.006147666  , 0.187132244  , 23.797653959  , 0.185919172  , 0.021272952  , 0.008553962  , 0.184739228 );
        kernels[17] = compute_kernel(x, 15,  0.197756293  , 0.197756293  , 0.0  , 0.001222646  , 5.007959646  , 0.039432753  , 35.0  , 0.669599218  , 0.005231244  , 0.197799608  , 25.312805474  , 0.197756293  , 0.004139251  , 0.006760762  , 0.197713209 );
        kernels[18] = compute_kernel(x, 15,  0.365347019  , 0.365347019  , 0.321664223  , 0.321972079  , 20.850497215  , 0.164177143  , 48.0  , 2.170087977  , 0.016953812  , 0.40360192  , 46.764418377  , 0.365347019  , 0.171511124  , 0.021900932  , 0.33420346 );
        kernels[19] = compute_kernel(x, 15,  0.203751222  , 0.203751222  , 0.0  , 0.001301725  , 5.331863713  , 0.041983179  , 34.0  , 0.796676442  , 0.006224035  , 0.20409602  , 26.080156403  , 0.203751222  , 0.011858534  , 0.008982995  , 0.203419368 );
        kernels[20] = compute_kernel(x, 15,  0.90076674  , 0.90076674  , 0.90076674  , 0.90076674  , 103.992627056  , 0.818839583  , 38.0  , 0.91886608  , 0.007178641  , 0.901355867  , 115.298142717  , 0.90076674  , 0.032583416  , 0.008845842  , 0.900209602 );
        kernels[21] = compute_kernel(x, 15,  0.251939761  , 0.251939761  , 0.115049181  , 0.115988327  , 8.385004142  , 0.066023655  , 30.0  , 0.684261975  , 0.005345797  , 0.255945004  , 32.248289345  , 0.251939761  , 0.045102128  , 0.007685238  , 0.248135564 );
        kernels[22] = compute_kernel(x, 15,  0.212953629  , 0.212953629  , 0.010118829  , 0.011465263  , 5.850602324  , 0.046067735  , 31.0  , 0.742913001  , 0.005804008  , 0.213793898  , 27.258064516  , 0.212953629  , 0.018936276  , 0.008738875  , 0.212145166 );
        kernels[23] = compute_kernel(x, 15,  0.868042827  , 0.868042827  , 0.868042827  , 0.868042827  , 96.459128223  , 0.759520695  , 43.0  , 0.889540567  , 0.006949536  , 0.868093854  , 111.109481916  , 0.868042827  , 0.009412169  , 0.008674062  , 0.867991943 );
        kernels[24] = compute_kernel(x, 15,  0.233267656  , 0.233267656  , 0.031731122  , 0.03317059  , 6.998062166  , 0.055102852  , 33.0  , 0.703812317  , 0.005498534  , 0.233821215  , 29.85826002  , 0.233267656  , 0.016079837  , 0.007334585  , 0.232753154 );
        kernels[25] = compute_kernel(x, 15,  0.205469514  , 0.205469514  , 0.0  , 0.00132142  , 5.412535152  , 0.042618387  , 31.0  , 0.576735093  , 0.004505743  , 0.205634216  , 26.300097752  , 0.205469514  , 0.008228598  , 0.006774659  , 0.205307961 );
        kernels[26] = compute_kernel(x, 15,  0.211235337  , 0.211235337  , 0.011989858  , 0.013297415  , 5.748335689  , 0.045262486  , 38.0  , 0.987292278  , 0.007713221  , 0.211917136  , 27.038123167  , 0.211235337  , 0.016985431  , 0.011226126  , 0.210590201 );
        kernels[27] = compute_kernel(x, 15,  1.233084372  , 1.233084372  , 1.233084372  , 1.233084372  , 213.928257124  , 1.684474466  , 46.0  , 2.375366569  , 0.018557551  , 1.292793297  , 157.834799609  , 1.233084372  , 0.388352212  , 0.031160291  , 1.174421173 );
        kernels[28] = compute_kernel(x, 15,  0.877703446  , 0.877703446  , 0.877703446  , 0.877703446  , 98.654217896  , 0.776804865  , 51.0  , 1.285434995  , 0.010042461  , 0.877915758  , 112.346041056  , 0.877703446  , 0.01930644  , 0.012073783  , 0.877491793 );
        kernels[29] = compute_kernel(x, 15,  0.197450819  , 0.197450819  , 0.0  , 0.00121889  , 4.992575457  , 0.039311618  , 27.0  , 0.45943304  , 0.003589321  , 0.197495559  , 25.27370479  , 0.197450819  , 0.004203565  , 0.00490679  , 0.197406294 );
        kernels[30] = compute_kernel(x, 15,  0.910465543  , 0.910465543  , 0.910465543  , 0.910465543  , 106.150187907  , 0.835828251  , 50.0  , 0.953079179  , 0.007445931  , 0.910658192  , 116.539589443  , 0.910465543  , 0.018730694  , 0.009107765  , 0.910272875 );
        kernels[31] = compute_kernel(x, 15,  0.86197153  , 0.86197153  , 0.86197153  , 0.86197153  , 95.114851093  , 0.748935835  , 46.0  , 0.943304008  , 0.007369563  , 0.862023651  , 110.332355816  , 0.86197153  , 0.009479238  , 0.008919956  , 0.861919611 );
        kernels[32] = compute_kernel(x, 15,  0.381384409  , 0.381384409  , 0.345720308  , 0.345988832  , 20.227150896  , 0.159268905  , 49.0  , 0.860215054  , 0.00672043  , 0.397523102  , 48.817204301  , 0.381384409  , 0.112118461  , 0.00854296  , 0.364245003 );
        kernels[33] = compute_kernel(x, 15,  0.869952041  , 0.869952041  , 0.869952041  , 0.869952041  , 96.950180071  , 0.763387245  , 47.0  , 1.295210166  , 0.010118829  , 0.870300685  , 111.353861193  , 0.869952041  , 0.024631868  , 0.013680566  , 0.869604825 );
        kernels[34] = compute_kernel(x, 15,  0.890800648  , 0.890800648  , 0.890800648  , 0.890800648  , 101.597065155  , 0.799976891  , 47.0  , 1.089931574  , 0.00851509  , 0.890913616  , 114.022482893  , 0.890800648  , 0.014187239  , 0.010543535  , 0.890687596 );
        kernels[35] = compute_kernel(x, 15,  0.19997098  , 0.19997098  , 0.0  , 0.001255038  , 5.140636332  , 0.040477451  , 33.0  , 0.664711632  , 0.00519306  , 0.200402648  , 25.596285435  , 0.19997098  , 0.013146426  , 0.006939249  , 0.199535866 );
        kernels[36] = compute_kernel(x, 15,  0.196878055  , 0.196878055  , 0.0  , 0.001216832  , 4.984142819  , 0.039245219  , 39.0  , 0.997067449  , 0.007789589  , 0.1973287  , 25.200391007  , 0.196878055  , 0.013328441  , 0.009561161  , 0.19642756 );
        kernels[37] = compute_kernel(x, 15,  0.205316777  , 0.205316777  , 0.0  , 0.001323239  , 5.419988362  , 0.042677074  , 35.0  , 0.830889541  , 0.006491325  , 0.205775749  , 26.28054741  , 0.205316777  , 0.013736095  , 0.008251764  , 0.204855285 );
        kernels[38] = compute_kernel(x, 15,  0.202758431  , 0.202758431  , 0.0  , 0.00129111  , 5.288386657  , 0.04164084  , 41.0  , 0.928641251  , 0.00725501  , 0.203262197  , 25.953079179  , 0.202758431  , 0.014301727  , 0.009281651  , 0.202252394 );
        kernels[39] = compute_kernel(x, 15,  0.190310362  , 0.190310362  , 0.0  , 0.001136091  , 4.653430531  , 0.036641185  , 35.0  , 0.752688172  , 0.005880376  , 0.190669678  , 24.359726295  , 0.190310362  , 0.011700097  , 0.007734034  , 0.189954037 );
        kernels[40] = compute_kernel(x, 15,  0.231702102  , 0.231702102  , 0.066058773  , 0.06718579  , 7.021114561  , 0.055284367  , 25.0  , 0.757575758  , 0.005918561  , 0.234206015  , 29.657869013  , 0.231702102  , 0.034155433  , 0.008148541  , 0.229396624 );
        kernels[41] = compute_kernel(x, 15,  0.909205462  , 0.909205462  , 0.909205462  , 0.909205462  , 105.858772189  , 0.833533639  , 47.0  , 1.114369501  , 0.008706012  , 0.909407311  , 116.37829912  , 0.909205462  , 0.019159484  , 0.011057302  , 0.909004221 );
        kernels[42] = compute_kernel(x, 15,  0.908709066  , 0.908709066  , 0.908709066  , 0.908709066  , 105.743940206  , 0.83262945  , 42.0  , 0.909090909  , 0.007102273  , 0.90891393  , 116.314760508  , 0.908709066  , 0.019296771  , 0.009362363  , 0.908504734 );
        kernels[43] = compute_kernel(x, 15,  0.923410007  , 0.923410007  , 0.923410007  , 0.923410007  , 109.193175727  , 0.859788785  , 41.0  , 0.957966764  , 0.007484115  , 0.923618799  , 118.196480938  , 0.923410007  , 0.019637814  , 0.00975591  , 0.923203892 );
        kernels[44] = compute_kernel(x, 15,  0.891029753  , 0.891029753  , 0.891029753  , 0.891029753  , 101.657885257  , 0.800455789  , 43.0  , 1.085043988  , 0.008476906  , 0.891180245  , 114.051808407  , 0.891029753  , 0.016377043  , 0.010903126  , 0.89087936 );
        kernels[45] = compute_kernel(x, 15,  0.911572886  , 0.911572886  , 0.911572886  , 0.911572886  , 106.492963883  , 0.838527275  , 44.0  , 1.094819159  , 0.008553275  , 0.912127338  , 116.681329423  , 0.911572886  , 0.031798642  , 0.010694101  , 0.911010759 );
        kernels[46] = compute_kernel(x, 15,  0.221774194  , 0.221774194  , 0.025010692  , 0.02635278  , 6.353670085  , 0.050028898  , 29.0  , 0.811339198  , 0.006338587  , 0.222795977  , 28.387096774  , 0.221774194  , 0.02131325  , 0.00886708  , 0.220799169 );
        kernels[47] = compute_kernel(x, 15,  0.234604106  , 0.234604106  , 0.053267045  , 0.054549635  , 7.122927315  , 0.056086042  , 34.0  , 0.869990225  , 0.006796799  , 0.235898007  , 30.029325513  , 0.234604106  , 0.024673534  , 0.008845842  , 0.233376283 );
        kernels[48] = compute_kernel(x, 15,  0.316127505  , 0.316127505  , 0.316127505  , 0.316127505  , 12.885142218  , 0.101457813  , 26.0  , 0.601173021  , 0.004696664  , 0.317277755  , 40.464320626  , 0.316127505  , 0.026992114  , 0.006359336  , 0.315028433 );
        kernels[49] = compute_kernel(x, 15,  0.177365897  , 0.177365897  , 0.0  , 0.000986363  , 4.040141267  , 0.031812136  , 24.0  , 0.581622678  , 0.004543927  , 0.177661486  , 22.7028348  , 0.177365897  , 0.010244134  , 0.006269973  , 0.177073505 );
        kernels[50] = compute_kernel(x, 15,  0.930855938  , 0.930855938  , 0.930855938  , 0.930855938  , 110.945611636  , 0.873587493  , 51.0  , 1.153470186  , 0.009011486  , 0.931000854  , 119.149560117  , 0.930855938  , 0.01642598  , 0.010781688  , 0.930710019 );
        kernels[51] = compute_kernel(x, 15,  0.719582417  , 0.719582417  , 0.719582417  , 0.719582417  , 75.10362828  , 0.591367152  , 51.0  , 2.204301075  , 0.017221102  , 0.765994188  , 92.106549365  , 0.719582417  , 0.262579971  , 0.052485241  , 0.660386447 );
        kernels[52] = compute_kernel(x, 15,  0.19092131  , 0.19092131  , 0.0  , 0.001142658  , 4.680328973  , 0.036852984  , 28.0  , 0.635386119  , 0.004963954  , 0.191219952  , 24.437927664  , 0.19092131  , 0.010682862  , 0.006605969  , 0.19061834 );
        kernels[53] = compute_kernel(x, 15,  0.329110154  , 0.329110154  , 0.329110154  , 0.329110154  , 14.044594082  , 0.110587355  , 20.0  , 0.650048876  , 0.005078507  , 0.331245213  , 42.126099707  , 0.329110154  , 0.037548606  , 0.007060175  , 0.326980684 );
        kernels[54] = compute_kernel(x, 15,  0.228570992  , 0.228570992  , 0.053648888  , 0.054858669  , 6.770667607  , 0.053312343  , 29.0  , 0.816226784  , 0.006376772  , 0.229990958  , 29.257086999  , 0.228570992  , 0.025517488  , 0.008813888  , 0.227122039 );
        kernels[55] = compute_kernel(x, 15,  0.906303458  , 0.906303458  , 0.906303458  , 0.906303458  , 105.211346269  , 0.828435797  , 49.0  , 1.133919844  , 0.008858749  , 0.906622106  , 116.00684262  , 0.906303458  , 0.024035075  , 0.011158903  , 0.905985925 );
        kernels[56] = compute_kernel(x, 15,  0.220781403  , 0.220781403  , 0.050861437  , 0.05199691  , 6.347315746  , 0.049978864  , 38.0  , 0.811339198  , 0.006338587  , 0.22268454  , 28.26001955  , 0.220781403  , 0.029051273  , 0.007926213  , 0.218848454 );
        kernels[57] = compute_kernel(x, 15,  0.239453507  , 0.239453507  , 0.072626466  , 0.073841916  , 7.379752496  , 0.058108287  , 37.0  , 0.943304008  , 0.007369563  , 0.240113132  , 30.650048876  , 0.239453507  , 0.017785793  , 0.00945234  , 0.238768197 );
        kernels[58] = compute_kernel(x, 15,  0.297913612  , 0.297913612  , 0.297913612  , 0.297913612  , 11.423094821  , 0.089945629  , 46.0  , 0.826001955  , 0.00645314  , 0.298735549  , 38.132942326  , 0.297913612  , 0.02214516  , 0.00796173  , 0.297132398 );
        kernels[59] = compute_kernel(x, 15,  0.919935239  , 0.919935239  , 0.919935239  , 0.919935239  , 108.438801027  , 0.853848827  , 44.0  , 1.011730205  , 0.007904142  , 0.920422801  , 117.751710655  , 0.919935239  , 0.029954769  , 0.010217367  , 0.919447333 );
        kernels[60] = compute_kernel(x, 15,  0.318647666  , 0.318647666  , 0.318647666  , 0.318647666  , 13.089054388  , 0.10306342  , 28.0  , 0.591397849  , 0.004620296  , 0.319778419  , 40.786901271  , 0.318647666  , 0.026868239  , 0.006209683  , 0.317557412 );
        kernels[61] = compute_kernel(x, 15,  0.29852456  , 0.29852456  , 0.29852456  , 0.29852456  , 11.42643921  , 0.089971962  , 42.0  , 0.698924731  , 0.005460349  , 0.298779277  , 38.211143695  , 0.29852456  , 0.01233464  , 0.006871149  , 0.298271139 );
        kernels[62] = compute_kernel(x, 15,  0.917720552  , 0.917720552  , 0.917720552  , 0.917720552  , 107.829023372  , 0.849047428  , 34.0  , 0.913978495  , 0.007140457  , 0.917831273  , 117.468230694  , 0.917720552  , 0.014255981  , 0.009291779  , 0.917609776 );
        kernels[63] = compute_kernel(x, 15,  0.201116508  , 0.201116508  , 0.046928458  , 0.047835941  , 5.361604886  , 0.042217361  , 34.0  , 0.713587488  , 0.005574902  , 0.204664453  , 25.742913001  , 0.201116508  , 0.037943227  , 0.007636131  , 0.197938715 );
        kernels[64] = compute_kernel(x, 15,  0.244111987  , 0.244111987  , 0.139105266  , 0.13971419  , 8.335913291  , 0.065637113  , 45.0  , 1.045943304  , 0.008171432  , 0.255194676  , 31.246334311  , 0.244111987  , 0.074388578  , 0.011309593  , 0.23349085 );
        kernels[65] = compute_kernel(x, 15,  0.22585991  , 0.22585991  , 0.067738881  , 0.068792348  , 6.669022072  , 0.052511985  , 38.0  , 1.021505376  , 0.007980511  , 0.228258045  , 28.910068426  , 0.22585991  , 0.033000548  , 0.010772961  , 0.223466589 );
        double decision = 0;
decision = decision - ( + kernels[0] * -1.0  + kernels[1] * -1.0  + kernels[2] * -1.0  + kernels[3] * -1.0  + kernels[4] * -1.0  + kernels[5] * -0.5658836777167344  + kernels[6] * -1.0  + kernels[7] * -1.0  + kernels[8] * -1.0  + kernels[9] * -1.0  + kernels[10] * -0.31671395181714895  + kernels[11] * -0.835170020199419  + kernels[12] * -1.0  + kernels[13] * -0.48217246797968055  + kernels[14] * -1.0  + kernels[15] * -1.0  + kernels[16] * -1.0  + kernels[17] * -0.494228107367833  + kernels[18] * -1.0  + kernels[19] * -1.0  + kernels[20] * -1.0  + kernels[21] * -1.0  + kernels[22] * -1.0  + kernels[23] * -1.0  + kernels[24] * -1.0  + kernels[25] * -1.0  + kernels[26] * -1.0  + kernels[27] * -0.17193729784742673  + kernels[28] * -1.0  + kernels[29] * -1.0  + kernels[30] * -0.8108905425287594  + kernels[31] * -1.0  + kernels[32] * -1.0  + kernels[33] * -1.0 );
decision = decision - ( + kernels[34] * 1.0  + kernels[35] * 1.0  + kernels[36] * 1.0  + kernels[37] * 1.0  + kernels[38] * 1.0  + kernels[39] * 1.0  + kernels[40] * 1.0  + kernels[41] * 1.0  + kernels[42] * 1.0  + kernels[43] * 1.0  + kernels[44] * 1.0  + kernels[45] * 1.0  + kernels[46] * 1.0  + kernels[47] * 1.0  + kernels[48] * 1.0  + kernels[49] * 1.0  + kernels[50] * 1.0  + kernels[51] * 1.0  + kernels[52] * 1.0  + kernels[53] * 1.0  + kernels[54] * 1.0  + kernels[55] * 1.0  + kernels[56] * 1.0  + kernels[57] * 1.0  + kernels[58] * 0.7278762453137778  + kernels[59] * 1.0  + kernels[60] * 0.08877264886802445  + kernels[61] * 0.8603471712751994  + kernels[62] * 1.0  + kernels[63] * 1.0  + kernels[64] * 1.0  + kernels[65] * 1.0 );
return decision > 0 ? 0 : 1;
}

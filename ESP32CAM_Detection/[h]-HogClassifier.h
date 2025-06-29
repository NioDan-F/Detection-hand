#ifndef UUID2362739974832
#define UUID2362739974832

/**
  * DecisionTreeClassifier(ccp_alpha=0.0, class_name=DecisionTreeClassifier, class_weight=None, criterion=gini, max_depth=30, max_features=None, max_leaf_nodes=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, monotonic_cst=None, num_outputs=3, package_name=everywhereml.sklearn.tree, random_state=None, splitter=best, template_folder=everywhereml/sklearn/tree)
 */
class DecisionTreeClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
    
    if (x[0] <= 0.011483604088425636) {
        
            
    if (x[89] <= 0.16037239134311676) {
        
            
    predictedValue = 0; /* A */

        
    }
    else {
        
            
    if (x[270] <= 0.03521631192415953) {
        
            
    predictedValue = 1; /* B */

        
    }
    else {
        
            
    predictedValue = 2; /* C */

        
    }

        
    }

        
    }
    else {
        
            
    if (x[72] <= 0.14970837533473969) {
        
            
    if (x[68] <= 0.13661455363035202) {
        
            
    if (x[19] <= 0.988644003868103) {
        
            
    if (x[81] <= 0.5) {
        
            
    predictedValue = 2; /* C */

        
    }
    else {
        
            
    predictedValue = 0; 

        
    }

        
    }
    else {
        
            
    predictedValue = 1;

        
    }

        
    }
    else {         
    predictedValue = 0;
    }    
    }
    else {
        
            
    if (x[319] <= 0.7145605832338333) {
        
            
    if (x[103] <= 0.01666863914579153) {
        
            
    predictedValue = 1; /* B */

        
    }
    else {
        
            
    predictedValue = 2;

        
    }

        
    }
    else {
        
            
    predictedValue = 0;

        
    }

        
    }

        
    }



            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }


        

/**
 * Predict class label
 */
String predictLabel(float *x) {
    return getLabelOf(predict(x));
}

/**
 * Get label of last prediction
 */
String getLabel() {
    return getLabelOf(lastPrediction);
}

/**
 * Get label of given class
 */
String getLabelOf(int8_t idx) {
    switch (idx) {
        case -1:
            return "ERROR";
        
            case 0:
                return "00500A";
        
            case 1:
                return "00500B";
        
            case 2:
                return "00500C";
        
        default:
            return "UNKNOWN";
    }
}


        /**
 * Get latency in micros
 */
uint32_t latencyInMicros() {
    return latency;
}

/**
 * Get latency in millis
 */
uint16_t latencyInMillis() {
    return latency / 1000;
}

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
};



static DecisionTreeClassifier classifier;


#endif

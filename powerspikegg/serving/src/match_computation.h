#ifndef POWERSPIKEGG_SERVING_SRC_MATCH_COMPUTATION_H_
#define POWERSPIKEGG_SERVING_SRC_MATCH_COMPUTATION_H_

#include <grpc++/grpc++.h>

#include <memory>

#include "tensorflow_serving/model_servers/server_core.h"
#include "powerspikegg/serving/public/match_computation.grpc.pb.h"

class MatchComputationImpl final : public serving::MatchComputation::Service {
 public:
    /**
     * Intstanciate a new Tensorflow Serving ServerCore to execute Tensorflow
     * models
     **/ 
    MatchComputationImpl();

    /**
     * Use the Tensorflow models specified in the request to compute 
     * featues for the match given in the request
     **/
    grpc::Status GetFeature(grpc::ServerContext* context,
                            const serving::MatchComputationRequest* match,
                            serving::MatchComputationFeature* feature);

 private:
    /**
     * The ServerCore is used to execute Tensorflow models
     **/
    std::unique_ptr<tensorflow::serving::ServerCore> core;
};

#endif  // POWERSPIKEGG_SERVING_SRC_MATCH_COMPUTATION_H_




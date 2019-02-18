//
// Created by Rabia on 16/02/2019.
//

#ifndef HOLEFILLING_PIXELCONNECTIVITY_H
#define HOLEFILLING_PIXELCONNECTIVITY_H

#include <memory>
#include "Pixel.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"


class PixelConnectivity
{

public:
    enum Connectivity
    {
        FOUR,
        EIGHT,
    };

    PixelConnectivity() = delete;
    PixelConnectivity(const PixelConnectivity& pixelConnectivity) = delete;
    ~PixelConnectivity() = default;

    PixelConnectivity(Connectivity connectivity,
                      float connectivityValue,
                      std::shared_ptr<cv::Mat> image);

    /**
     *
     * @param atRow position on x axis
     * @param atColumn position on y axis
     * @return true if the pixel is connected
     *      according to connectivityValue in the image
     */
    bool isConnected(int atRow, int atColumn);

    Connectivity getConnectivity() const;

private:

    bool isFourConnected(int atRow, int atColumn);

    bool isEightConnected(int atRow, int atColumn);

    bool equalsConnectivityValue(int atRow, int atColumn);

    float connectivityValue_;

    Connectivity connectivity_;

    std::shared_ptr<cv::Mat> image_;

    static constexpr char ILLEGAL_CONNECTIVITY_ERROR[] =
            "illegal pixel connectivity";

};


#endif //HOLEFILLING_PIXELCONNECTIVITY_H

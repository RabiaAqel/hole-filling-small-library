//
// Created by Rabia on 16/02/2019.
//

#include "PixelConnectivity.h"

#include "../../exceptions/IllegalPixelConnectivity.h"


constexpr char PixelConnectivity::ILLEGAL_CONNECTIVITY_ERROR[];


PixelConnectivity::
PixelConnectivity(Connectivity connectivity,
                  float connectivityValue,
                  std::shared_ptr<cv::Mat> image)
        : connectivity_(connectivity),
          connectivityValue_(connectivityValue),
          image_(std::move(image)) {}


bool PixelConnectivity::isConnected(int atRow, int atColumn)
{
    switch ( connectivity_ )
    {
        case FOUR:
            return isFourConnected(atRow, atColumn);
        case EIGHT:
            return isEightConnected(atRow, atColumn);
        default:
            throw IllegalPixelConnectivity(ILLEGAL_CONNECTIVITY_ERROR);

    }
}


bool PixelConnectivity::isFourConnected(int atRow, int atColumn)
{

    if ( equalsConnectivityValue(atRow - 1, atColumn))
        return true;
    if ( equalsConnectivityValue(atRow + 1, atColumn))
        return true;
    if ( equalsConnectivityValue(atRow, atColumn - 1))
        return true;
    return equalsConnectivityValue(atRow, atColumn + 1);

}


bool PixelConnectivity::isEightConnected(int atRow, int atColumn)
{

    if ( isFourConnected(atRow, atColumn))
        return true;
    if ( equalsConnectivityValue(atRow - 1, atColumn - 1))
        return true;
    if ( equalsConnectivityValue(atRow + 1, atColumn + 1))
        return true;
    if ( equalsConnectivityValue(atRow - 1, atColumn + 1))
        return true;
    return equalsConnectivityValue(atRow + 1, atColumn - 1);

}


bool PixelConnectivity::
    equalsConnectivityValue(int atRow, int atColumn)
{
    if ( atRow >= image_->rows || atRow < 0
         || atColumn >= image_->cols || atColumn < 0 )
        return false;
    else
        return image_->at<float>(atRow, atColumn) == connectivityValue_;
}


PixelConnectivity::Connectivity
    PixelConnectivity::getConnectivity() const
{
    return connectivity_;
}
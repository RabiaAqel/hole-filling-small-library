//
// Created by Rabia on 14/02/2019.
//

#ifndef HOLEFILLING_IMAGECONVERTER_H
#define HOLEFILLING_IMAGECONVERTER_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

using cv::Mat;
using std::shared_ptr;
using std::string;


class ImageUtil
{
public:
    ImageUtil() = delete;

    /**
     *
     * @param imagePath a path to an image
     * @param maskPath a path to a mask
     * @return a cv::Mat of a float Grayscale image
     * which has -1 marking the hole according to
     * white pixels in the mask
     */
    static Mat toFloatImageWithHole(const string &imagePath, const string &maskPath);

    /**
     *
     * @param image an image of type cv::Mat
     * @param target a path denote where to save the image
     * @param fileName file name to use for saving the image
     */
    static void saveImageTo(const Mat& image, const std::string& target,
                            const std::string& fileName);

    /**
     *
     * @param image an image of type cv::Mat
     * @return the image normalized to Grayscale
     */
    static Mat normalizeToGrayscale(const Mat& image);

private:
    static constexpr char EMPTY_IMAGE_ERROR[] = "empty image";
    static constexpr char EMPTY_MASK_ERROR[] = "empty mask";
    static constexpr char SIZE_MISMATCH_ERROR[] = "image and mask has different dims";


};


#endif //HOLEFILLING_IMAGECONVERTER_H

#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

class QImage;

class ImageProcessing
{
public:
    explicit ImageProcessing(int width, int height, int dataSize);
    void chromakeyProcess(QImage& sourceImage, QImage& targetImage, QImage& resultImage);

private:
    int imageWidth;
    int imageHeight;
    int imageDataSize;
};

#endif // IMAGEPROCESSING_H

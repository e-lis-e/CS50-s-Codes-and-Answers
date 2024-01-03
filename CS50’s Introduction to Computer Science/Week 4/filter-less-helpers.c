#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set what gray is: an average between the colors
            int gray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // set the color to gray in each rgb part
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // using the sepia formula given by the platform
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // changing each rgb color to it sepia version while checking the amount of pixels
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : (sepiaRed < 0) ? 0 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : (sepiaGreen < 0) ? 0 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : (sepiaBlue < 0) ? 0 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp[height][width];
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE extra[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            extra[i][j].rgbtRed = image[i][j].rgbtRed;
            extra[i][j].rgbtGreen = image[i][j].rgbtGreen;
            extra[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int aB, aG, aR;
            aB = aG = aR = 0;

            for (int k = (i - 1); k <= (i + 1); k++)
            {
                for (int l = (j - 1); l <= (j + 1); l++)
                {
                    if ((k >= 0 && k <= (height - 1)) && (l >= 0 && l <= (width - 1)))
                    {
                        aR += extra[k][l].rgbtRed;
                        aG += extra[k][l].rgbtGreen;
                        aB += extra[k][l].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = (int) round((double) aR / (double) count);
            image[i][j].rgbtGreen = (int) round((double) aG / (double) count);
            image[i][j].rgbtBlue = (int) round((double) aB / (double) count);
        }
    }
    return;
}
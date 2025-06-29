// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{s
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy THE FIRST 44 BYTES FROM from header input file to header output file
    uint8_t header[HEADER_SIZE];

    fread(&header, sizeof(header), 1, input);

    fwrite(&header, sizeof(header), 1, output);

    // TODO: Read samples from input file and write updated data to output file

    int16_t buffer;

    while (fread(&buffer, sizeof(buffer), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(buffer), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

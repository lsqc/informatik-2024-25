package com.lsdevcloud.utils.files;

/**
 * Created: 24.01.25
 *
 * @author lsdevcloud (lesc@lsdevcloud.com)
 */
public final class ByteSizeUtil
{
    private static final String[] DECIMAL_UNITS = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    private static final String[] IEC_UNITS = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
    
    private static final long DECIMAL_UNIT_THRESHOLD = 1000;
    private static final long IEC_UNIT_TRESHHOLD = 1024;

    // used to prevent instantiation of this class
    private ByteSizeUtil()
    {
    }

    /**
     * Formats a given size and returns it as string with matching SI-prefix
     *
     * @param sizeInBytes Size in bytes
     * @return Formatted size with prefix
     */
    public static String siByteSize(double sizeInBytes)
    {
        if (sizeInBytes < 0)
        {
            throw new IllegalArgumentException("File size must be positive");
        }

        double size = sizeInBytes;
        int unitIndex = 0;

        while (size >= DECIMAL_UNIT_THRESHOLD && unitIndex < DECIMAL_UNITS.length - 1)
        {
            size /= DECIMAL_UNIT_THRESHOLD;
            unitIndex++;
        }

        return String.format("%.2f %s", size, DECIMAL_UNITS[unitIndex]);
    }
    
    /**
     * Formats a given size of bytes and returns it as a string with the matching IEC-prefix
     *
     * @param sizeInBytes input size of bytes
     * @return formatted size with iec-prefix
     */
    public static String iecByteSize(double sizeInBytes)
    {
        if (sizeInBytes < 0)
        {
            throw new IllegalArgumentException("File size must be positive");
        }

        double size = sizeInBytes;
        int unitIndex = 0;

        while (size >= IEC_UNIT_TRESHHOLD && unitIndex < IEC_UNITS.length - 1)
        {
            size /= IEC_UNIT_TRESHHOLD;
            unitIndex++;
        }

        return String.format("%.2f %s", size, IEC_UNITS[unitIndex]);
    }
}

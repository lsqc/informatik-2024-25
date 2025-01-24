package com.lsdevcloud.utils.files;

/**
 * Created: 24.01.25
 *
 * @author lsdevcloud (lesc@lsdevcloud.com)
 */
public final class ByteSizeUtil
{

    private static final String[] UNITS = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    private static final long UNIT_THRESHOLD = 1024;

    private ByteSizeUtil()
    {
    }

    /**
     * Formats a given size and returns it as string with matching SI-prefix
     *
     * @param sizeInBytes Size in bytes
     * @return Formatted size with prefix
     */
    public static String formatFileSize(long sizeInBytes)
    {
        if (sizeInBytes < 0)
        {
            throw new IllegalArgumentException("File size must be positive");
        }

        double size = sizeInBytes;
        int unitIndex = 0;

        while (size >= UNIT_THRESHOLD && unitIndex < UNITS.length - 1)
        {
            size /= UNIT_THRESHOLD;
            unitIndex++;
        }

        return String.format("%.2f %s", size, UNITS[unitIndex]);
    }
}

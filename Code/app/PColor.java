package Code.app;

import java.awt.Color;

public enum PColor {
    FULL_DARK(new Color(52, 78, 65)), DARK(new Color(58, 90, 64)), MEDIUM(new Color(88, 129, 87)), LIGHT(new Color(163, 177, 138)), FULL_LIGHT(new Color(218, 215, 205));
    private final Color color;

    PColor(Color color) {
        this.color = color;
    }

    public Color get() {
        return color;
    }
}
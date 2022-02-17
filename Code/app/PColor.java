package Code.app;

import java.awt.Color;

public enum PColor {
    FULL_DARK(new Color(3, 25, 38)), DARK(new Color(70, 129, 137)), MEDIUM(new Color(119, 172, 162)),
    LIGHT(new Color(157, 190, 187)), FULL_LIGHT(new Color(244, 233, 205));

    private final Color color;

    private PColor(Color color) {
        this.color = color;
    }

    public Color get() {
        return this.color;
    }
}

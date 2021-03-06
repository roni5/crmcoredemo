<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_navigation_openlayers_behaviors() {
  return array(
    'title' => t('Navigation'),
    'description' => t('Provides the ability to navigate the map interface.  This is just for user interactions and does not show any visual controls.  This behavior automatically includes the Pan Zoom, Zoom Box, and Pinch Zoom controls.'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_navigation.inc',
      'class' => 'openlayers_behavior_navigation',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Navigation Behavior
 */
class openlayers_behavior_navigation extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'navigation' => '',
      'zoomWheelEnabled' => TRUE,
      'zoomBoxEnabled' => TRUE,
      'documentDrag' => FALSE,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.Navigation');
  }

  function options_form($defaults = array()) {
    return array(
      'zoomWheelEnabled' => array(
        '#type' => 'checkbox',
        '#title' => t('Enable Zoom Wheel'),
        '#description' => t('Enable zooming via the mouse scroll wheel. This can
          interfere with page scrolling.'),
        '#default_value' => isset($defaults['zoomWheelEnabled']) ? $defaults['zoomWheelEnabled'] : TRUE
      ),
      'zoomBoxEnabled' => array(
        '#type' => 'checkbox',
        '#title' => t('Enable Zoom Box'),
        '#description' => t('Enable zooming with selecting a box by <em>SHIFT + clicking</em>.'),
        '#default_value' => isset($defaults['zoomBoxEnabled']) ? $defaults['zoomBoxEnabled'] : TRUE
      ),
      'documentDrag' => array(
        '#type' => 'checkbox',
        '#title' => t('Document Drag'),
        '#description' => t('Allow panning of the map by dragging outside map viewport.'),
        '#default_value' => isset($defaults['documentDrag']) ? $defaults['documentDrag'] : FALSE
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_navigation.js');
    return $this->options;
  }
}

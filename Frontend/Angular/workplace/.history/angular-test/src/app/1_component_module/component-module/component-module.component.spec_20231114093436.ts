import { TestBed } from '@angular/core/testing';
import { Component } from '@angular/core';
import { ComponentModuleComponent } from './component-module.component';

describe('ComponentModuleComponent', () => {
  let component_module_component: ComponentModuleComponent; // Add this

  beforeEach(() => {
    TestBed.configureTestingModule({
      providers: [ComponentModuleComponent]
    });

    component_module_component = TestBed.get(ComponentModuleComponent); // Add this
  });

  it('should be created', () => { // Remove inject()
    expect(component_module_component).toBeTruthy();
  });
});
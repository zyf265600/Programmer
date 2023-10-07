import { ComponentFixture, TestBed } from '@angular/core/testing';

import { FormArrayComponent } from './form-array.component';

describe('FormArrayComponent', () => {
  let component: FormArrayComponent;
  let fixture: ComponentFixture<FormArrayComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [FormArrayComponent]
    });
    fixture = TestBed.createComponent(FormArrayComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

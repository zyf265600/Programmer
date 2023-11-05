import { ComponentFixture, TestBed } from '@angular/core/testing';

import { TopsecretComponent } from './topsecret.component';

describe('TopsecretComponent', () => {
  let component: TopsecretComponent;
  let fixture: ComponentFixture<TopsecretComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [TopsecretComponent]
    });
    fixture = TestBed.createComponent(TopsecretComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

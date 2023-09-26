import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AppComponentComponent } from './app-component.component';

describe('AppComponentComponent', () => {
  let component: AppComponentComponent;
  let fixture: ComponentFixture<AppComponentComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [AppComponentComponent]
    });
    fixture = TestBed.createComponent(AppComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
